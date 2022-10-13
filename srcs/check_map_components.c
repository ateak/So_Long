/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:12:36 by ateak             #+#    #+#             */
/*   Updated: 2022/05/03 19:20:11 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_components_amount(t_symbol *map_components, t_game *map)
{
	if (map_components->exit_score < 1)
		ft_error_and_free("Error\nThere is no exit!\n", map);
	else if (map_components->item_score < 1)
		ft_error_and_free("Error\nThere is no collectible!\n", map);
	else if (map_components->player_score < 1)
		ft_error_and_free("Error\nThere is no player!\n", map);
	else if (map_components->player_score > 1)
		ft_error_and_free("Error\nToo many players!\n", map);
}

static void	map_components_amount(t_game *map, t_symbol *map_components)
{
	if (map->data[map_components->i][map_components->j] == 'E')
		map_components->exit_score++;
	else if (map->data[map_components->i][map_components->j] == 'C')
		map_components->item_score++;
	else if (map->data[map_components->i][map_components->j] == 'P')
	{
		map_components->player_score++;
		map->player_pos_x = map_components->j;
		map->player_pos_y = map_components->i;
	}		
}

void	check_wrong_map_components(t_game *map, t_symbol *map_components,
		char	*symbols)
{
	while (map_components->i < map->width)
	{
		map_components->j = 0;
		while (map_components->j < map->length)
		{
			map_components->s = 0;
			map_components->match = 0;
			while (map_components->s < 5)
			{
				if (map->data[map_components->i][map_components->j] ==
					symbols[map_components->s])
				{
					map_components->match++;
					map_components_amount(map, map_components);
					break ;
				}
				map_components->s++;
			}
			if (map_components->match == 0)
				ft_error_and_free("Error\nWrong characters in the map!\n", map);
			map_components->j++;
		}
		map_components->i++;
	}
	check_map_components_amount(map_components, map);
}
