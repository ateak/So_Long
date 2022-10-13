# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateak <ateak@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:34:27 by ateak             #+#    #+#              #
#    Updated: 2022/10/13 15:37:45 by ateak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
NAME_BONUS		=	so_long_bonus

SRCS			=	./srcs/check_map.c\
					./srcs/check_map_components.c\
					./srcs/get_next_line.c\
					./srcs/init_and_render.c\
					./srcs/main.c\
					./srcs/movements.c\
					./srcs/so_long_utils.c\

SRCS_BONUS		=	./srcs_bonus/check_map_bonus.c\
					./srcs_bonus/check_map_components_bonus.c\
					./srcs_bonus/get_next_line_bonus.c\
					./srcs_bonus/init_bonus.c\
					./srcs_bonus/render_bonus.c\
					./srcs_bonus/render_animation_bonus.c\
					./srcs_bonus/main_bonus.c\
					./srcs_bonus/movements_bonus.c\
					./srcs_bonus/so_long_utils_bonus.c\

LIBDIR			= 	libft
LIBFT_LIB		= 	$(LIBDIR)/libft.a
LIB				=	-L$(LIBDIR) -lft
MLXDIR			= 	minilibx
MLX_LIB			=	$(MLXDIR)/libmlx.a
MLX				=	-L$(MLXDIR) -lft
	
					
HEADER 			= 	./srcs/so_long.h	
HEADER_BONUS 	= 	./srcs_bonus/so_long_bonus.h	

OBJS			=	$(SRCS:%.c=%.o)
OBJS_BONUS 		= 	$(SRCS_BONUS:%.c=%.o)
OBJS_DIR		=	srcs/
OBJS_DIR_BONUS	=	srcs_bonus/

CFLAGS			=	-Wall -Wextra -Werror 
MLX_FLAGS		=	-lmlx -framework OpenGL -framework AppKit

RM = rm -f

.PHONY	:	all clean fclean re make_lib

all		:	$(NAME)

$(NAME)	:	$(LIBFT_LIB) $(MLX_LIB) $(OBJS)
			$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(LIBDIR) $(LIB) -I$(MLXDIR) $(MLX) $(OBJS)  -o ${NAME}

$(OBJS_DIR)%.o: 	$(OBJS_DIR)%.c $(HEADER)
					$(CC) $(CFLAGS) -I$(LIBDIR) -I$(MLXDIR) -c $< -o $@
	
$(LIBFT_LIB):	make_lib

make_lib	:	
		make -C $(LIBDIR) 
		make -C $(MLXDIR)

bonus	: $(NAME_BONUS)

$(NAME_BONUS):	$(LIBFT_LIB) $(OBJS_BONUS)
				$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(LIBDIR) $(LIB) -I$(MLXDIR) $(MLX) $(OBJS_BONUS)  -o ${NAME_BONUS} 

$(OBJS_DIR_BONUS)%.o: 	$(OBJS_DIR_BONUS)%.c $(HEADER_BONUS)
						$(CC) $(CFLAGS) -I$(LIBDIR) -I$(MLXDIR) -c $< -o $@

clean	:
	make clean -C $(LIBDIR) 
	make clean -C $(MLXDIR)
	$(RM) $(OBJS) $(OBJS_BONUS) 

fclean	: 	clean
	$(RM) $(NAME) $(NAME_BONUS)

re		:	fclean all