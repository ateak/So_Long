/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:29:52 by ateak             #+#    #+#             */
/*   Updated: 2022/05/12 13:26:25 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_moves(t_game *map)
{
	char	*str;

	str = ft_itoa(map->steps);
	mlx_string_put(map->mlx, map->window, 5, 6, 0xffd700, "Steps: ");
	mlx_string_put(map->mlx, map->window, 70, 6, 0xffd700, str);
	free(str);
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

void	ft_mlx_put_image(t_game *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->window, map->floor,
		y * 100, x * 100);
	if (map->data[x][y] == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->wall,
			y * 100, x * 100);
	else if (map->data[x][y] == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->player,
			y * 100, x * 100);
	else if (map->data[x][y] == 'E')
		ft_render_exit(map, x, y);
}

int	ft_render(t_game *map)
{
	int			x;
	int			y;
	static int	count = 0;

	if (count++ < 1000)
		return (0);
	x = -1;
	while (map->data[++x])
	{
		y = -1;
		while (map->data[x][++y])
			ft_mlx_put_image(map, x, y);
	}
	create_animation(map);
	print_moves(map);
	count = 0;
	return (0);
}
