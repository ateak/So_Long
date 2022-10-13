/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:38 by ateak             #+#    #+#             */
/*   Updated: 2022/05/12 13:30:51 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_exit(void)
{
	ft_putstr_fd("See you next time!\n", 1);
	exit(EXIT_SUCCESS);
}

void	ft_error_exit(char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

static void	check_empty_strings(char *map_string)
{
	int	i;

	i = 0;
	while (map_string[i])
	{
		if (map_string[i] == '\n' && map_string[i + 1] == '\n')
		{
			free(map_string);
			ft_error_exit("Error\nMap with empty strings!\n");
		}
		i++;
	}
}

void	read_map(t_game *map, int fd)
{
	char	*map_string;
	char	*tmp;
	char	*tmp2;

	map_string = NULL;
	tmp = NULL;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		ft_error_exit("Error\nThe map is empty!\n");
	while (tmp)
	{
		tmp2 = map_string;
		map_string = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free (tmp);
		tmp = get_next_line(fd);
	}
	check_empty_strings(map_string);
	*map = (t_game){};
	map->data = ft_split(map_string, '\n');
	free(map_string);
}	

int	main(int argc, char **argv)
{
	t_game		*map;
	t_symbol	*map_components;
	int			fd;

	if (argc != 2)
		ft_error_exit("Error\nWrong number of arguments!\n");
	check_map_format(argv);
	fd = open_file(argv);
	map = malloc(sizeof(t_game));
	if (map == NULL)
		ft_error_exit("Error\nMalloc for map failed\n");
	map_components = malloc(sizeof(t_symbol));
	if (map_components == NULL)
		ft_error_exit("Error\nMalloc for map_components failed\n");
	read_map(map, fd);
	close(fd);
	check_map(map, map_components);
	init(map, map_components);
	ft_render(map);
	mlx_key_hook(map->window, ft_key_hook, map);
	mlx_hook(map->window, 17, 0, ft_exit, 0);
	mlx_loop_hook(map->mlx, ft_render, map);
	mlx_loop(map->mlx);
	return (0);
}
