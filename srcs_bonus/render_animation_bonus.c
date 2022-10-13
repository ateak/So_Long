/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:42:55 by ateak             #+#    #+#             */
/*   Updated: 2022/05/11 18:47:08 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_render_enemy_anim(int x, int y, t_game *map, int animation_enemy)
{
	if (animation_enemy == 0)
		mlx_put_image_to_window(map->mlx, map->window, map->enemy_00,
			y * 100, x * 100);
	else if (animation_enemy == 1)
		mlx_put_image_to_window(map->mlx, map->window, map->enemy_01,
			y * 100, x * 100);
	else if (animation_enemy == 2)
		mlx_put_image_to_window(map->mlx, map->window, map->enemy_02,
			y * 100, x * 100);
	else if (animation_enemy == 3)
		mlx_put_image_to_window(map->mlx, map->window, map->enemy_03,
			y * 100, x * 100);
}

static void	ft_render_item_anim(int x, int y, t_game *map, int animation_item)
{
	if (animation_item == 0)
		mlx_put_image_to_window(map->mlx, map->window, map->item_00,
			y * 100, x * 100);
	else if (animation_item == 1)
		mlx_put_image_to_window(map->mlx, map->window, map->item_01,
			y * 100, x * 100);
	else if (animation_item == 2)
		mlx_put_image_to_window(map->mlx, map->window, map->item_02,
			y * 100, x * 100);
	else if (animation_item == 3)
		mlx_put_image_to_window(map->mlx, map->window, map->item_03,
			y * 100, x * 100);
}

int	create_animation(t_game *map)
{
	int			x;
	int			y;
	static int	animation_item;
	static int	animation_enemy;

	x = -1;
	while (map->data[++x])
	{
		y = -1;
		while (map->data[x][++y])
		{
			if (map->data[x][y] == 'C')
				ft_render_item_anim(x, y, map, animation_item);
			if (map->data[x][y] == 'B')
				ft_render_enemy_anim(x, y, map, animation_enemy);
		}
	}
	animation_enemy++;
	animation_item++;
	if (animation_item > 3)
		animation_item = 0;
	if (animation_enemy > 3)
		animation_enemy = 0;
	return (1);
}
