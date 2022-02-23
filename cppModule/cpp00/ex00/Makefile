FLAGS = -Wall -Wextra -Werror
SRCS = ./megaphone.cpp
NAME = megaphone

OBJS = ${SRCS:.c=.o}
all : ${NAME}

.c.o: $(SRCS) ${LIBFT}
	c++ $(FLAGS) -c -o $@ $<

$(NAME) :  $(OBJS)
	c++ $(FLAGS) -o $(NAME)  $(OBJS)


clean :
		rm -rf $(OBJS)
fclean : 
	rm -rf ./megaphone

re : fclean all