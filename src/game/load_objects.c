/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:22:21 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 19:31:07 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_img	*load_grass(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./assets/grass.png");
	if (!grass)
		print_error("Error loading grass", 0);
	img->grass = mlx_texture_to_image(mlx_ptr, grass);
	if (!img->grass)
		print_error("Error with grass texture", 0);
	mlx_delete_texture(grass);
	return (img);
}

t_img	*load_object(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*object;

	object = mlx_load_png("./assets/coin.png");
	if (!object)
		print_error("Error loading object", 0);
	img->object = mlx_texture_to_image(mlx_ptr, object);
	if (!img->object)
		print_error("Error with object texture", 0);
	mlx_delete_texture(object);
	return (img);
}

t_img	*load_wall(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./assets/fence.png");
	if (!wall)
		print_error("Error loading wall", 0);
	img->wall = mlx_texture_to_image(mlx_ptr, wall);
	if (!img->wall)
		print_error("Error with wall texture", 0);
	mlx_delete_texture(wall);
	return (img);
}

t_img	*load_enemy1(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./assets/skel1.png");
	if (!enemy)
		print_error("Error loading enemy", 0);
	img->enemy->enemy1 = mlx_texture_to_image(mlx_ptr, enemy);
	if (!img->enemy->enemy1)
		print_error("Error with enemy texture", 0);
	mlx_delete_texture(enemy);
	return (img);
}

t_img	*load_enemy2(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./assets/skel3.png");
	if (!enemy)
		print_error("Error loading enemy", 0);
	img->enemy->enemy2 = mlx_texture_to_image(mlx_ptr, enemy);
	if (!img->enemy->enemy2)
		print_error("Error with enemy texture", 0);
	mlx_delete_texture(enemy);
	return (img);
}
