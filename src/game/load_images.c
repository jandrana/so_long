/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:55:09 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 19:30:09 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_img	*load_exit(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./assets/chest1.png");
	if (!exit)
		print_error("Error loading exit", 0);
	img->exit = mlx_texture_to_image(mlx_ptr, exit);
	if (!img->exit)
		print_error("Error with exit texture", 0);
	mlx_delete_texture(exit);
	return (img);
}

t_img	*load_exit2(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./assets/chest4.png");
	if (!exit)
		print_error("Error loading exit", 0);
	img->exit2 = mlx_texture_to_image(mlx_ptr, exit);
	if (!img->exit2)
		print_error("Error with exit texture", 0);
	mlx_delete_texture(exit);
	return (img);
}

t_img	*initialize_images(mlx_t *mlx_ptr)
{
	t_img	*assets;
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	assets = (t_img *)malloc(sizeof(t_img));
	if (!assets)
		return (NULL);
	assets->enemy = enemy;
	assets = load_grass(mlx_ptr, assets);
	assets = load_wall(mlx_ptr, assets);
	assets = load_player_up(mlx_ptr, assets);
	assets = load_player_down(mlx_ptr, assets);
	assets = load_player_left(mlx_ptr, assets);
	assets = load_player_right(mlx_ptr, assets);
	assets = load_exit(mlx_ptr, assets);
	assets = load_exit2(mlx_ptr, assets);
	assets = load_object(mlx_ptr, assets);
	assets = load_enemy1(mlx_ptr, assets);
	assets = load_enemy2(mlx_ptr, assets);
	return (assets);
}
