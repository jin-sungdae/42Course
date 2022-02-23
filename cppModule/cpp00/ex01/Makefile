FLAGS = -Wall -Wextra -Werror
SRCS = ./phonebook.cpp ./main.cpp ./array.cpp
NAME = phonebook

OBJS = ${SRCS:.c=.o}
all : ${NAME}

.c.o: $(SRCS) ${LIBFT}
	c++ $(FLAGS) -c -o $@ $<

$(NAME) :  $(OBJS)
	c++ $(FLAGS) -o $(NAME)  $(OBJS)

clean :
		rm -rf $(OBJS)
fclean : 
	rm -rf $(NAME)

re : fclean all