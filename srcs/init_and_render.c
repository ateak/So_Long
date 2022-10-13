/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:57:00 by ateak             #+#    #+#             */
/*   Updated: 2022/05/12 13:25:05 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_image(void *str, t_game *map)
{
	if (str == NULL)
		ft_error_and_free("Error\nTexture not found!\n", map);
}

static void	ft_render_exit(t_game *map, int x, int y)
{
	if (map->current_score == map->max_score)
		mlx_put_image_to_window(map->mlx, map->window, map->exit_fin,
			y * 100, x * 100);
	else
		mlx_put_image_to_window(map->mlx, map->window, map->exit,
			y * 100, x * 100);
}

void	ft_render(t_game *map)
{
	int	x;
	int	y;

	x = -1;
	while (map->data[++x])
	{
		y = -1;
		while (map->data[x][++y])
		{
			mlx_put_image_to_window(map->mlx, map->window, map->floor,
				y * 100, x * 100);
			if (map->data[x][y] == '1')
				mlx_put_image_to_window(map->mlx, map->window, map->wall,
					y * 100, x * 100);
			if (map->data[x][y] == 'P')
				mlx_put_image_to_window(map->mlx, map->window, map->player,
					y * 100, x * 100);
			if (map->data[x][y] == 'C')
				mlx_put_image_to_window(map->mlx, map->window, map->item,
					y * 100, x * 100);
			if (map->data[x][y] == 'E')
				ft_render_exit(map, x, y);
		}
	}
}

void	init_map(t_game *map, t_symbol *map_components)
{
	int	c;

	map->mlx = mlx_init();
	if (map->mlx == NULL)
		ft_error_and_free("Error\nMlx_init failed\n", map);
	map->window = mlx_new_window(map->mlx, 100 * map->length,
			100 * map->width, "so_long");
	if (map->window == NULL)
		ft_error_and_free("Error\nMlx_new_window_creating failed\n", map);
	map->floor = mlx_xpm_file_to_image(map->mlx, "textures/Floor.xpm", &c, &c);
	check_image(map->floor, map);
	map->wall = mlx_xpm_file_to_image(map->mlx, "textures/Wall.xpm", &c, &c);
	check_image(map->wall, map);
	map->item = mlx_xpm_file_to_image(map->mlx, "textures/Item.xpm", &c, &c);
	check_image(map->item, map);
	map->exit = mlx_xpm_file_to_image(map->mlx, "textures/Exit.xpm", &c, &c);
	check_image(map->exit, map);
	map->exit_fin = mlx_xpm_file_to_image(map->mlx,
			"textures/Exit_fin.xpm", &c, &c);
	check_image(map->exit_fin, map);
	map->player = mlx_xpm_file_to_image(map->mlx, "textures/Plr.xpm", &c, &c);
	check_image(map->player, map);
	map->current_score = 0;
	map->max_score = map_components->item_score;
}
