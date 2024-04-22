/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:13:50 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 13:50:24 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	check_num_items(t_map *map)
{
	int	row;
	int	col;

	if (map->player != 1 || map->exit != 1 || !map->object)
		print_error("Invalid number of items", map);
	row = 0;
	while (++row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (row == 0 || col == 0 || col == map->width - 1
				|| row == map->height)
			{
				if (map->value[row][col] != '1')
					print_error("Map not surrounded by walls", map);
			}
			col++;
		}
		row++;
	}
	return (1);
}

static int	check_map_items(char c, t_map *map, int row, int col)
{
	if (c == 'P')
	{
		map->player++;
		map->row_start = row;
		map->col_start = col;
		map->value[row][col] = c;
	}
	else if (c == 'E')
	{
		map->exit++;
		map->value[row][col] = c;
	}
	else if (c == 'C')
	{
		map->object++;
		map->value[row][col] = c;
	}
	else if (c == '0' || c == '1' || c == 'D')
		map->value[row][col] = c;
	else
		return (0);
	return (1);
}

static int	check_map(int fd, t_map *map)
{
	char	*line;
	int		i;
	int		cur_width;

	i = -1;
	line = get_next_line(fd);
	while (line && ++i > -1)
	{
		cur_width = -1;
		while (line[++cur_width] && line[cur_width] != '\n')
		{
			if (!check_map_items(line[cur_width], map, i, cur_width))
				return (free(line), print_error("Unknown object", map), 0);
		}
		free(line);
		if (!map->width)
			map->width = cur_width;
		if (map->width != cur_width)
			print_error("Map not rectangular", map);
		line = get_next_line(fd);
	}
	map->height = i + 1;
	return (1);
}

static int	check_file_type(char *str, char *type)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 3;
	while (str[i] && j >= 0)
	{
		if (str[i] != type[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

t_map	*valid_input(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0 || !check_file_type(argv[1], ".ber"))
			print_error(0, map);
		else if (!check_map(fd, map) || map->height < 2 || map->width < 3)
			print_error("Invalid height/width", map);
		else if (!check_num_items(map))
			print_error(0, map);
		else if (!valid_path(map, map->row_start, map->col_start)
			|| !search_objects(map))
			print_error("Invalid path", map);
	}
	else
		print_error("Invalid number of arguments", map);
	return (map);
}
