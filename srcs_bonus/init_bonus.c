/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:57:00 by ateak             #+#    #+#             */
/*   Updated: 2022/05/12 13:32:00 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_image(void *str, t_game *map)
{
	if (str == NULL)
		ft_error_and_free("Error\nTexture not found!\n", map);
}

static void	init_animation(t_game *map)
{
	int	c;

	map->enemy_00 = mlx_xpm_file_to_image(map->mlx, "anim/En_00.xpm", &c, &c);
	check_image(map->enemy_00, map);
	map->enemy_01 = mlx_xpm_file_to_image(map->mlx, "anim/En_01.xpm", &c, &c);
	check_image(map->enemy_01, map);
	map->enemy_02 = mlx_xpm_file_to_image(map->mlx, "anim/En_02.xpm", &c, &c);
	check_image(map->enemy_02, map);
	map->enemy_03 = mlx_xpm_file_to_image(map->mlx, "anim/En_03.xpm", &c, &c);
	check_image(map->enemy_03, map);
	map->item_00 = mlx_xpm_file_to_image(map->mlx, "anim/Item_00.xpm", &c, &c);
	check_image(map->item_00, map);
	map->item_01 = mlx_xpm_file_to_image(map->mlx, "anim/Item_01.xpm", &c, &c);
	check_image(map->item_01, map);
	map->item_02 = mlx_xpm_file_to_image(map->mlx, "anim/Item_02.xpm", &c, &c);
	check_image(map->item_02, map);
	map->item_03 = mlx_xpm_file_to_image(map->mlx, "anim/Item_03.xpm", &c, &c);
	check_image(map->item_03, map);
}

static void	init_map(t_game *map, t_symbol *map_components)
{
	int	c;

	map->mlx = mlx_init();
	if (map->mlx == NULL)
		ft_error_and_free("Error\nMlx_init failed\n", map);
	map->window = mlx_new_window(map->mlx, 100 * map->length,
			100 * map->width, "so_long_bonus");
	if (map->window == NULL)
		ft_error_and_free("Error\nMlx_new_window_creating failed\n", map);
	map->floor = mlx_xpm_file_to_image(map->mlx, "textures/Floor.xpm", &c, &c);
	check_image(map->floor, map);
	map->wall = mlx_xpm_file_to_image(map->mlx, "textures/Wall.xpm", &c, &c);
	check_image(map->wall, map);
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

void	init(t_game *map, t_symbol *map_components)
{
	init_map(map, map_components);
	init_animation(map);
}
