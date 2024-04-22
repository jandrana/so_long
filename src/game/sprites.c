/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:03:06 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 19:03:03 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	open_exit(t_data *data, int x, int y)
{
	if (mlx_image_to_window(data->mlx_ptr, data->map->img->grass, x * PIXELS, y
			* PIXELS) < 0)
		print_error("Error loading background", 0);
	if (mlx_image_to_window(data->mlx_ptr, data->map->img->exit2,
			x * PIXELS + PIXELS / 4, y * PIXELS + PIXELS / 4) < 0)
		print_error("Error loading exit", 0);
}

void	check_exit(t_data	*data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height && !data->map->object)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->value[y][x] == 'E')
				open_exit(data, x, y);
			x++;
		}
		y++;
	}
}

void	update_sprite(t_data *data, int x, int y, int skel)
{
	if (mlx_image_to_window(data->mlx_ptr, data->map->img->grass, x * PIXELS, y
			* PIXELS) < 0)
		print_error("Error loading background", 0);
	else if (skel)
	{
		if (mlx_image_to_window(data->mlx_ptr, data->map->img->enemy->enemy2, x
				* PIXELS + PIXELS / 4, y * PIXELS + PIXELS / 4) < 0)
			print_error("Error loading enemy", 0);
	}
	else
	{
		if (mlx_image_to_window(data->mlx_ptr, data->map->img->enemy->enemy1, x
				* PIXELS + PIXELS / 4, y * PIXELS + PIXELS / 4) < 0)
			print_error("Error loading enemy", 0);
	}
}

void	sprites_anim(void *param)
{
	int		x;
	int		y;
	t_data	*data;

	data = param;
	y = 0;
	data->map->frames++;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->value[y][x] == 'D' && !(data->map->frames % 40))
				update_sprite(data, x, y, 0);
			else if (data->map->value[y][x] == 'D' && !(data->map->frames % 20))
				update_sprite(data, x, y, 1);
			x++;
		}
		y++;
	}
}
