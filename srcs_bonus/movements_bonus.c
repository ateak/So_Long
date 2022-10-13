/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:15:53 by ateak             #+#    #+#             */
/*   Updated: 2022/05/11 18:35:10 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_move_forward(t_game *map)
{
	if (map->data[map->player_pos_y - 1][map->player_pos_x] == 'C'
	|| map->data[map->player_pos_y - 1][map->player_pos_x] == '0')
	{
		if (map->data[map->player_pos_y - 1][map->player_pos_x] == 'C')
			(map->current_score)++;
		map->data[map->player_pos_y - 1][map->player_pos_x] = 'P';
		map->data[map->player_pos_y--][map->player_pos_x] = '0';
		return (1);
	}
	if ((map->data[map->player_pos_y - 1][map->player_pos_x] == 'E')
	&& (map->current_score == map->max_score))
		ft_norm_exit("Good job!\n", map);
	if (map->data[map->player_pos_y - 1][map->player_pos_x] == 'B')
		ft_norm_exit("Oops, you've been captured by aliens!\n", map);
	return (0);
}

static int	ft_move_back(t_game *map)
{
	if (map->data[map->player_pos_y + 1][map->player_pos_x] == 'C'
	|| map->data[map->player_pos_y + 1][map->player_pos_x] == '0')
	{
		if (map->data[map->player_pos_y + 1][map->player_pos_x] == 'C')
			(map->current_score)++;
		map->data[map->player_pos_y + 1][map->player_pos_x] = 'P';
		map->data[map->player_pos_y++][map->player_pos_x] = '0';
		return (1);
	}
	if ((map->data[map->player_pos_y + 1][map->player_pos_x] == 'E')
	&& (map->current_score == map->max_score))
		ft_norm_exit("Good job!\n", map);
	if (map->data[map->player_pos_y + 1][map->player_pos_x] == 'B')
		ft_norm_exit("Oops, you've been captured by aliens!\n", map);
	return (0);
}

static int	ft_move_left(t_game *map)
{
	if (map->data[map->player_pos_y][map->player_pos_x - 1] == 'C'
	|| map->data[map->player_pos_y][map->player_pos_x - 1] == '0')
	{
		if (map->data[map->player_pos_y][map->player_pos_x - 1] == 'C')
			(map->current_score)++;
		map->data[map->player_pos_y][map->player_pos_x - 1] = 'P';
		map->data[map->player_pos_y][map->player_pos_x--] = '0';
		return (1);
	}
	if ((map->data[map->player_pos_y][map->player_pos_x - 1] == 'E')
	&& (map->current_score == map->max_score))
		ft_norm_exit("Good job!\n", map);
	if (map->data[map->player_pos_y][map->player_pos_x - 1] == 'B')
		ft_norm_exit("Oops, you've been captured by aliens!\n", map);
	return (0);
}

static int	ft_move_right(t_game *map)
{
	if (map->data[map->player_pos_y][map->player_pos_x + 1] == 'C'
	|| map->data[map->player_pos_y][map->player_pos_x + 1] == '0')
	{
		if (map->data[map->player_pos_y][map->player_pos_x + 1] == 'C')
			(map->current_score)++;
		map->data[map->player_pos_y][map->player_pos_x + 1] = 'P';
		map->data[map->player_pos_y][map->player_pos_x++] = '0';
		return (1);
	}
	if ((map->data[map->player_pos_y][map->player_pos_x + 1] == 'E')
	&& (map->current_score == map->max_score))
		ft_norm_exit("Good job!\n", map);
	if (map->data[map->player_pos_y][map->player_pos_x + 1] == 'B')
		ft_norm_exit("Oops, you've been captured by aliens!\n", map);
	return (0);
}

int	ft_key_hook(int keycode, t_game *map)
{
	int			step;

	step = 0;
	if (keycode == 13)
		step += ft_move_forward(map);
	else if (keycode == 1)
		step += ft_move_back(map);
	else if (keycode == 0)
		step += ft_move_left(map);
	else if (keycode == 2)
		step += ft_move_right(map);
	else if (keycode == 53)
		ft_norm_exit("See you next time!\n", map);
	if (step != 0)
	{
		map->steps++;
		ft_render(map);
	}
	return (0);
}
