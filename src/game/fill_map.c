/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:58:18 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 14:01:25 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	add_player(t_data *data, int x, int y)
{
	mlx_image_t	*player;

	player = NULL;
	if (!(data->map->last) || data->map->last == 'S')
		player = data->map->img->player_down;
	else if (data->map->last == 'W')
		player = data->map->img->player_up;
	else if (data->map->last == 'A')
		player = data->map->img->player_left;
	else if (data->map->last == 'D')
		player = data->map->img->player_right;
	if (player && mlx_image_to_window(data->mlx_ptr, player,
			x * PIXELS + PIXELS / 4, y * PIXELS + PIXELS / 4) < 0)
		print_error("Error loading player", 0);
}

void	add_images(t_data *data, int x, int y)
{
	if (data->map->value[y][x] == '1')
	{
		if (mlx_image_to_window(data->mlx_ptr, data->map->img->wall,
				x * PIXELS, y * PIXELS) < 0)
			print_error("Error loading wall", 0);
	}
	if (data->map->value[y][x] == 'E')
	{
		if (mlx_image_to_window(data->mlx_ptr, data->map->img->exit,
				x * PIXELS + PIXELS / 4, y * PIXELS + PIXELS / 4) < 0)
			print_error("Error loading exit", 0);
	}
	if (data->map->value[y][x] == 'C')
	{
		if (mlx_image_to_window(data->mlx_ptr, data->map->img->object,
				x * PIXELS + PIXELS / 4, y * PIXELS + PIXELS / 4) < 0)
			print_error("Error loading object", 0);
	}
	if (data->map->value[y][x] == 'P')
		add_player(data, x, y);
}

void	fill_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (mlx_image_to_window(data->mlx_ptr, data->map->img->grass,
					x * PIXELS, y * PIXELS) < 0)
				print_error("Error loading background", 0);
			add_images(data, x, y);
			x++;
		}
		y++;
	}
}
