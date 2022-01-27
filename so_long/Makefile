# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 22:35:41 by sjin              #+#    #+#              #
#    Updated: 2021/07/05 22:35:58 by sjin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MMSPATH = ./minilibx
CLFLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
SRC =  ./srcs/check_some.c ./srcs/description.c ./srcs/description2.c ./srcs/draw_function1.c ./srcs/draw_function2.c \
		./srcs/free1.c ./srcs/init_first.c ./srcs/init_second.c ./srcs/libft1.c ./srcs/libft2.c ./srcs/libft3.c ./srcs/list_check_move_check.c \
		./srcs/list_check.c ./srcs/load_image.c ./srcs/map_checker_utils.c ./srcs/map_checker.c ./srcs/map_player.c \
		./srcs/move_key.c ./srcs/out_put_information.c ./srcs/pixel_put_image.c ./srcs/some_function.c ./so_long.c

NAME = so_long
OBJ = ${SRC:.c=.o}
OBJS = ${GNL:.c=.o}

all : $(NAME)

.c.o: $(SRC) $(GNL)
	$(CC) $(CFLAGS) -c -o $@ $<

${NAME} :  ${OBJ}  ${OBJS}
		gcc ${FLAGS} -o ${NAME} ${OBJ} ${OBJS} -L $(MMSPATH) $(CLFLAGS)

clean : 
		rm -rf ${OBJ} ${OBJS}

fclean : clean
		rm -rf ${NAME}

re :	fclean all