/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:49:37 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/15 13:12:19 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <libft.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define MAX_ROWS 100
# define MAX_COLS 100
# define PIXELS	64

typedef struct s_enemy
{
	mlx_image_t	*enemy1;
	mlx_image_t	*enemy2;
	int			is_up;
}	t_enemy;

typedef struct s_img
{
	mlx_image_t	*grass;
	mlx_image_t	*wall;
	mlx_image_t	*player_up;
	mlx_image_t	*player_down;
	mlx_image_t	*player_left;
	mlx_image_t	*player_right;
	mlx_image_t	*exit;
	mlx_image_t	*exit2;
	mlx_image_t	*object;
	t_enemy		*enemy;
}	t_img;

typedef struct s_map
{
	int		height;
	int		width;
	char	value[MAX_ROWS][MAX_COLS];
	int		visited[MAX_ROWS][MAX_COLS];
	int		player;
	int		row_start;
	int		col_start;
	int		exit;
	int		object;
	int		moves;
	char	last;
	int		frames;
	t_img	*img;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
}	t_data;

t_map	*valid_input(int argc, char **argv);
int		valid_path(t_map *map, int x, int y);
void	print_error(char *str, t_map *map);
void	free_all(t_data *data);
void	finish_game(t_data *data, int finished);
t_img	*initialize_images(mlx_t *mlx_ptr);
void	fill_map(t_data *data);
void	process_mlx(t_data *data);
void	move_player(t_data *data, int x, int y, char move);
int		search_objects(t_map *map);
void	redraw_map(t_data *data, int x, int y, char move);
void	add_player(t_data *data, int x, int y);
void	add_images(t_data *data, int x, int y);
t_img	*load_player_up(mlx_t *mlx_ptr, t_img *img);
t_img	*load_player_down(mlx_t *mlx_ptr, t_img *img);
t_img	*load_player_left(mlx_t *mlx_ptr, t_img *img);
t_img	*load_player_right(mlx_t *mlx_ptr, t_img *img);
t_img	*load_exit(mlx_t *mlx_ptr, t_img *img);
t_img	*load_exit2(mlx_t *mlx_ptr, t_img *img);
t_img	*load_enemy1(mlx_t *mlx_ptr, t_img *img);
t_img	*load_enemy2(mlx_t *mlx_ptr, t_img *img);
t_img	*load_grass(mlx_t *mlx_ptr, t_img *img);
t_img	*load_wall(mlx_t *mlx_ptr, t_img *img);
t_img	*load_object(mlx_t *mlx_ptr, t_img *img);
void	update_sprite(t_data *data, int x, int y, int skel);
void	sprites_anim(void *param);
void	check_exit(t_data	*data);

#endif /* SO_LONG_H */
