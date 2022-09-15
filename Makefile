# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <snino@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 17:57:38 by snino             #+#    #+#              #
#    Updated: 2022/09/15 17:06:01 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= cub3D

CC 				:= gcc

HEADER 			:= cub3D.h

CFLAGS 			:= -g -Wall -Wextra -Werror

LIB				:=	libft/

LIB_mlx			:= -L ./minilibx -lmlx -framework OpenGL -framework AppKit

OBJ_DIR			:=	obj

SRCS 			:=	cub3D.c			ft_check_map.c			ft_check_type_mass.c\
					ft_pars_map.c	ft_utils_show.c			ft_error_handler.c\
					ft_free_game.c	ft_utils_pars_map.c		ft_free_map_game.c\

OBJ 			:=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS)))

.PHONY			:	all clean makelibft fclean re

all				:	makelibft $(NAME)

makelibft		:
					@make -C $(LIB) all

$(NAME)			:	$(HEADER) $(OBJ)
					$(MAKE) -C ./minilibx
					$(CC) $(CFLAGS) $(OBJ) $(LIB)libft.a -o $(NAME)

$(OBJ_DIR)/%.o	:	%.c	$(HEADER)
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) $(LIB_mlx) -c $< -o $@ -I .

clean			:
					@rm -rf $(OBJ_DIR)
					@make -C $(LIB) clean

fclean			:	clean
					$(MAKE) -C ./minilibx clean
					@$(RM) $(NAME)
					@make -C $(LIB) fclean

re				:	fclean all