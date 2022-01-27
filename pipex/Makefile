# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 19:35:14 by sjin              #+#    #+#              #
#    Updated: 2021/09/06 16:16:55 by sjin             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/ft_cmpchar.c ./libft/ft_freeall.c ./libft/ft_freelen.c ./libft/ft_putstr_len.c \
./libft/ft_split.c ./libft/ft_strcat.c ./libft/ft_strcpy.c ./libft/ft_strjoin.c ./libft/ft_strlen.c \
./libft/ft_strncmp.c ./libft/ft_strstr.c
SRCS = ./pipex.c ./get_path.c ./check_index.c ./check_index2.c ./init_index.c

NAME = pipex
OBJ = ${LIBFT:.c=.o}
OBJS =${SRCS:.c=.o}

all : ${NAME}

.c.o: $(SRCS) ${LIBFT}
	gcc $(FLAGS) -c -o $@ $<

$(NAME) : $(OBJ) $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(OBJS)

clean :
		rm -rf $(OBJ) $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all