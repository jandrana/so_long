/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:36:02 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 18:26:55 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	clear_visited(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x <= map->height)
	{
		y = 0;
		while (y < map->width)
		{
			map->visited[x][y] = 0;
			y++;
		}
		x++;
	}
}

static void	check_objects(t_map *map, int x, int y)
{
	clear_visited(map);
	if (!valid_path(map, x, y))
		print_error("Invalid object path", map);
}

int	search_objects(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x <= map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->value[x][y] == 'C')
				check_objects(map, x, y);
			y++;
		}
		x++;
	}
	return (1);
}

int	valid_path(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->height || y > map->width)
		return (0);
	if (map->value[x][y] == '1' || map->value[x][y] == 'D'
		|| map->visited[x][y])
		return (0);
	if (map->value[x][y] == 'E')
		return (1);
	map->visited[x][y] = 1;
	if (valid_path(map, x - 1, y) || valid_path(map, x + 1, y)
		|| valid_path(map, x, y - 1) || valid_path(map, x, y + 1))
		return (1);
	return (0);
}
