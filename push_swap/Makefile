# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjin <sjin@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 19:33:59 by sjin              #+#    #+#              #
#    Updated: 2021/08/02 19:34:01 by sjin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/ft_putstr_fd.c ./libft/ft_strncmp.c  ./libft/ft_strnequ.c ./libft/ft_atoi.c ./libft/ft_strlen.c ./libft/ft_strdup.c
SRCS = ./main.c ./get_pivot.c ./init.c ./sorted.c ./push_stack.c ./command1.c ./command2.c ./command3.c

NAME = push_swap
OBJ = $(LIBFT:.c=.o)
OBJS = $(SRCS:.c=.o)

all : ${NAME}

.c.o: ${SRCS} ${LIBFT}
	gcc $(FLAGS) -c -o $@ $<

$(NAME) : $(OBJ) $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(OBJS)

clean :
		rm -rf $(OBJ) $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all