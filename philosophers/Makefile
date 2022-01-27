
FLAGS = -Wall -Wextra -Werror
SRCS = ./philo.c ./philo_init.c ./philo_run.c ./philo_utils.c ./philo_exit.c ./philo_act.c

NAME = philo
OBJ = ${LIBFT:.c=.o}
OBJS =${SRCS:.c=.o}
INCLUDE	= -lpthread
all : ${NAME}

.c.o: $(SRCS) ${LIBFT}
	gcc $(FLAGS) -c -o $@ $<

$(NAME) : $(OBJ) $(OBJS)
	gcc $(FLAGS) $(INCLUDE) -o $(NAME) $(OBJ) $(OBJS)

clean :
		rm -rf $(OBJ) $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all