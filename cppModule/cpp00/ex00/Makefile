FLAGS = -Wall -Wextra -Werror
SRCS = ./Megaphone.cpp
NAME = memgaphone
OBJ = ${LIBFT:.c=.o}
OBJS =${SRCS:.c=.o}
all : ${NAME}

.c.o: $(SRCS) ${LIBFT}
	g++ $(FLAGS) -c -o $@ $<

$(NAME) : $(OBJ) $(OBJS)
	g++ $(FLAGS) $(INCLUDE) -o $(NAME) $(OBJ) $(OBJS)

clean :
		rm -rf $(OBJ) $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all