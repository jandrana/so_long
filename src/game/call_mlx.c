/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:29:58 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 18:38:01 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	process_moves(t_data *data, char move)
{
	char	*str;

	data->map->last = move;
	move_player(data, data->map->col_start, data->map->row_start, move);
	ft_printf("\rmoves: %i", data->map->moves);
	if (mlx_image_to_window(data->mlx_ptr, data->map->img->grass, 0 * PIXELS, 0
			* PIXELS) < 0)
		print_error("Error loading wall", 0);
	if (mlx_image_to_window(data->mlx_ptr, data->map->img->wall, 0 * PIXELS, 0
			* PIXELS) < 0)
		print_error("Error loading wall", 0);
	str = ft_itoa(data->map->moves);
	mlx_put_string(data->mlx_ptr, str, 20, 20);
	free(str);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		process_moves(data, 'W');
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		process_moves(data, 'A');
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		process_moves(data, 'S');
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		process_moves(data, 'D');
	if ((keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		&& keydata.action == MLX_PRESS)
		finish_game(data, 0);
}

void	process_mlx(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, sprites_anim, data);
	mlx_key_hook(data->mlx_ptr, &key_hook, data);
	mlx_loop(data->mlx_ptr);
	mlx_terminate(data->mlx_ptr);
}
