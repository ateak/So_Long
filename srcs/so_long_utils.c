/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:51:55 by ateak             #+#    #+#             */
/*   Updated: 2022/05/12 13:20:17 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	

void	open_file_error(char *str)
{
	write(2, "Error\n", 6);
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_destroy(t_game *map)
{
	mlx_destroy_image(map->mlx, map->item);
	mlx_destroy_image(map->mlx, map->floor);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->player);
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_window(map->mlx, map->window);
}

void	ft_free(t_game *map)
{
	size_t	i;

	i = 0;
	while (i < map->width)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	map->data = NULL;
}

void	ft_error_and_free(char *str, t_game *map)
{
	size_t	i;

	i = 0;
	if (str)
		ft_putstr_fd(str, 2);
	ft_free(map);
	exit(EXIT_FAILURE);
}

void	ft_norm_exit(char *str, t_game *map)
{
	if (str)
		ft_putstr_fd(str, 1);
	ft_destroy(map);
	ft_free(map);
	exit(EXIT_SUCCESS);
}
