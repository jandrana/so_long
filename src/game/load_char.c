/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:28:20 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 19:30:00 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_img	*load_player_up(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/Char_up.png");
	if (!player)
		print_error("Error loading player", 0);
	img->player_up = mlx_texture_to_image(mlx_ptr, player);
	if (!img->player_up)
		print_error("Error with player texture", 0);
	mlx_delete_texture(player);
	return (img);
}

t_img	*load_player_down(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/Char_down.png");
	if (!player)
		print_error("Error loading player", 0);
	img->player_down = mlx_texture_to_image(mlx_ptr, player);
	if (!img->player_down)
		print_error("Error with player texture", 0);
	mlx_delete_texture(player);
	return (img);
}

t_img	*load_player_left(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/Char_left.png");
	if (!player)
		print_error("Error loading player", 0);
	img->player_left = mlx_texture_to_image(mlx_ptr, player);
	if (!img->player_left)
		print_error("Error with player texture", 0);
	mlx_delete_texture(player);
	return (img);
}

t_img	*load_player_right(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/Char_right.png");
	if (!player)
		print_error("Error loading player", 0);
	img->player_right = mlx_texture_to_image(mlx_ptr, player);
	if (!img->player_right)
		print_error("Error with player texture", 0);
	mlx_delete_texture(player);
	return (img);
}
