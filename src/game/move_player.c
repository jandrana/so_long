/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:58:28 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 19:44:07 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	move_w(t_data *data, int x, int y)
{
	if (data->map->value[y - 1][x] == 'E' && data->map->object == 0)
		finish_game(data, 1);
	else if (data->map->value[y - 1][x] == 'D')
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("\n\033[0;31mYou died! Be careful next time :c\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	else if (data->map->value[y - 1][x] != 'E')
	{
		if (data->map->value[y - 1][x] == 'C')
		{
			data->map->object -= 1;
			check_exit(data);
		}
		data->map->row_start = y - 1;
		data->map->value[y - 1][x] = 'P';
		data->map->value[y][x] = '0';
		data->map->moves += 1;
	}
	return (1);
}

static int	move_a(t_data *data, int x, int y)
{
	if (data->map->value[y][x - 1] == 'E' && data->map->object == 0)
		finish_game(data, 1);
	else if (data->map->value[y][x - 1] == 'D')
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("\n\033[0;31mYou died! Be careful next time :c\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	else if (data->map->value[y][x - 1] != 'E')
	{
		if (data->map->value[y][x - 1] == 'C')
		{
			data->map->object -= 1;
			check_exit(data);
		}
		data->map->col_start = x - 1;
		data->map->value[y][x - 1] = 'P';
		data->map->value[y][x] = '0';
		data->map->moves += 1;
	}
	return (1);
}

static int	move_s(t_data *data, int x, int y)
{
	if (data->map->value[y + 1][x] == 'E' && data->map->object == 0)
		finish_game(data, 1);
	else if (data->map->value[y + 1][x] == 'D')
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("\n\033[0;31mYou died! Be careful next time :c\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	else if (data->map->value[y + 1][x] != 'E')
	{
		if (data->map->value[y + 1][x] == 'C')
		{
			data->map->object -= 1;
			check_exit(data);
		}
		data->map->row_start = y + 1;
		data->map->value[y + 1][x] = 'P';
		data->map->value[y][x] = '0';
		data->map->moves += 1;
	}
	return (1);
}

static int	move_d(t_data *data, int x, int y)
{
	if (data->map->value[y][x + 1] == 'E' && data->map->object == 0)
		finish_game(data, 1);
	else if (data->map->value[y][x + 1] == 'D')
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("\n\033[0;31mYou died! Be careful next time :c\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	else if (data->map->value[y][x + 1] != 'E')
	{
		if (data->map->value[y][x + 1] == 'C')
		{
			data->map->object -= 1;
			check_exit(data);
		}
		data->map->col_start = x + 1;
		data->map->value[y][x + 1] = 'P';
		data->map->value[y][x] = '0';
		data->map->moves += 1;
	}
	return (1);
}

void	move_player(t_data *data, int x, int y, char move)
{
	int	move_pl;

	move_pl = 0;
	if (move == 'W' && data->map->value[y - 1][x] != '1')
		move_pl = move_w(data, x, y);
	else if (move == 'A' && data->map->value[y][x - 1] != '1')
		move_pl = move_a(data, x, y);
	else if (move == 'S' && data->map->value[y + 1][x] != '1')
		move_pl = move_s(data, x, y);
	if (move == 'D' && data->map->value[y][x + 1] != '1')
		move_pl = move_d(data, x, y);
	if (move_pl)
		redraw_map(data, x, y, move);
}
