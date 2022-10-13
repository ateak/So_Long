/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:42:41 by ateak             #+#    #+#             */
/*   Updated: 2022/10/04 16:55:25 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_game
{
	size_t	length;
	size_t	width;
	size_t	player_pos_x;
	size_t	player_pos_y;
	size_t	current_score;
	size_t	max_score;
	char	**data;
	void	*mlx;
	void	*window;
	void	*item;
	void	*floor;
	void	*exit;
	void	*exit_fin;
	void	*player;
	void	*wall;
}					t_game;

typedef struct s_symbol
{
	size_t	item_score;
	size_t	floor_score;
	size_t	exit_score;
	size_t	wall_score;
	size_t	player_score;
	size_t	match;
	size_t	i;
	size_t	j;
	size_t	s;

}					t_symbol;

void	read_map(t_game *map, int fd);
void	check_map(t_game *map, t_symbol *map_components);
void	check_map_rectangularity(t_game *map);
void	check_map_walls(t_game *map);
void	check_wrong_map_components(t_game *map,
			t_symbol *map_components, char *symbols);
void	check_map_format(char **argv);
void	init_map(t_game *map, t_symbol *map_components);
void	ft_render(t_game *map);
int		ft_key_hook(int keycode, t_game *map);
void	ft_error_and_free(char *str, t_game *map);
void	open_file_error(char *str);
void	ft_error_exit(char *str);
void	ft_norm_exit(char *str, t_game *map);
void	ft_destroy(t_game *map);
void	ft_free(t_game *map);

char	*get_next_line(int fd);
char	*ft_read_file_and_form_tail(int fd, char *tail);
char	*ft_create_tail(char *buf, char *tail);
char	*ft_create_line(char *tail);
char	*ft_new_tail(char *tail);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#endif