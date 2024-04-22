/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:44:29 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/11 19:57:39 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_error(char *str, t_map *map)
{
	ft_printf("\033[0;31m");
	if (map)
		free(map);
	if (str)
		ft_printf("Error\n %s\n", str);
	else
		ft_printf("Error\n %s\n", strerror(errno));
	ft_printf("\033[0m");
	exit(EXIT_FAILURE);
}

void	finish_game(t_data *data, int finished)
{
	if (!finished)
	{
		if (data->map->img->enemy)
			free(data->map->img->enemy);
		if (data->map->img)
			free(data->map->img);
		if (data->map)
			free(data->map);
		mlx_close_window(data->mlx_ptr);
		ft_printf("\nYou quitted the game before finishing\n");
	}
	else
	{
		ft_printf("\rmoves: %i", ++data->map->moves);
		if (data->map->img->enemy)
			free(data->map->img->enemy);
		if (data->map->img)
			free(data->map->img);
		if (data->map)
			free(data->map);
		mlx_close_window(data->mlx_ptr);
		ft_printf("\n\033[0;32mYOU WON!\n You saved all the coins!\033[0m\n");
	}
	exit(EXIT_SUCCESS);
}

void	free_all(t_data *data)
{
	if (data->map->img->enemy)
		free(data->map->img->enemy);
	if (data->map->img)
		free(data->map->img);
	if (data->map)
		free(data->map);
	if (data)
		free(data);
}
