/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:05:35 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 20:01:35 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->map = valid_input(argc, argv);
	if (!data->map)
		return (0);
	data->mlx_ptr = mlx_init(data->map->width * PIXELS, data->map->height
			* PIXELS, "So_Long", true);
	if (!data->mlx_ptr)
		print_error(0, 0);
	data->win_ptr = mlx_new_image(data->mlx_ptr, data->map->width * PIXELS,
			data->map->height * PIXELS);
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		print_error(0, 0);
	}
	data->map->img = initialize_images(data->mlx_ptr);
	data->map->frames = 1;
	fill_map(data);
	process_mlx(data);
	free_all(data);
	return (0);
}
