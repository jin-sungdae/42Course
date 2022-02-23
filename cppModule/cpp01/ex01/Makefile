CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ./main.cpp ./Zombie.cpp ./ZombieHorde.cpp
NAME = zombie

OBJS = ${SRCS:.c=.o}
all : ${NAME}

.c.o: $(SRCS) ${LIBFT}
	c++ $(CXXFLAGS) -c -o $@ $<

$(NAME) :  $(OBJS)
	c++ $(CXXFLAGS) -o $(NAME)  $(OBJS)

clean :
		rm -rf $(OBJS)
fclean : 
	rm -rf $(NAME)

re : fclean all