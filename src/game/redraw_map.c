/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:43:30 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 13:49:12 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	redraw_map(t_data *data, int x, int y, char move)
{
	if (mlx_image_to_window(data->mlx_ptr, data->map->img->grass,
			x * PIXELS, y * PIXELS) < 0)
		print_error("Error loading player", 0);
	if (move == 'W' && data->map->value[y - 1][x] != 'E')
		y--;
	if (move == 'A' && data->map->value[y][x - 1] != 'E')
		x--;
	if (move == 'S' && data->map->value[y + 1][x] != 'E')
		y++;
	if (move == 'D' && data->map->value[y][x + 1] != 'E')
		x++;
	add_player(data, x, y);
}
