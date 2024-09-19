# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 15:45:12 by kalturan          #+#    #+#              #
#    Updated: 2024/04/26 22:30:48 by kalturan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFTDIR = ./libft
MLXDIR = ./minilibx

CC = cc
RM = rm -f
FLAGS =  -Wall -Werror -Wextra

SRC = creat_map.c ft_action.c ft_error.c ft_extension_check.c ft_free.c ft_key_hook.c ft_keys_moves.c valid_path_control.c so_long.c ft_check.c

OBJ = ${SRC:.c=.o}
INLIBFT = libft/libft.a
INMLX = minilibx/libmlx.a

${NAME}: ${OBJ}
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	${CC} ${FLAGS} ${OBJ} ${INLIBFT} ${INMLX} -framework OpenGL -framework Appkit -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJ}
		@cd $(LIBFTDIR) && $(MAKE) clean
		@cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
