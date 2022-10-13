/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:12:16 by ateak             #+#    #+#             */
/*   Updated: 2022/05/11 17:28:58 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_file(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		open_file_error("Can't open the file");
	return (fd);
}

void	check_map_format(char **argv)
{
	char			*map_format;
	int				len;
	unsigned int	start;

	len = 4;
	start = ft_strlen(argv[1]) - 4;
	map_format = ft_substr(argv[1], start, len);
	if (ft_strncmp(map_format, ".ber", len))
	{
		free(map_format);
		ft_error_exit("Error\nWrong map format!\n");
	}
	free(map_format);
}

void	check_map_walls(t_game *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < map->length)
	{
		if (map->data[0][j] != '1' || map->data[map->width - 1][j] != '1')
			ft_error_and_free("Error\nThere are no walls!\n", map);
		j++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->data[i][0] != '1' || map->data[i][map->length - 1] != '1')
			ft_error_and_free
			("Error\nThere are no walls!\n", map);
		i++;
	}
}

void	check_map_rectangularity(t_game *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
			j++;
		if ((map->data[i]) && (j != map->length))
			ft_error_and_free("Error\nThe map isn't rectangular!\n", map);
		i++;
	}
	map->data[i] = NULL;
}

void	check_map(t_game *map, t_symbol *map_components)
{
	char	*symbols;
	size_t	i;

	symbols = "01ECPB";
	*map_components = (t_symbol){};
	map->length = ft_strlen(map->data[0]);
	i = 0;
	while (map->data[i])
		i++;
	map->width = i;
	check_map_rectangularity(map);
	check_map_walls(map);
	check_wrong_map_components(map, map_components, symbols);
}
