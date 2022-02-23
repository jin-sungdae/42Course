CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ./main.cpp ./Animal.cpp ./Cat.cpp ./Dog.cpp ./WrongAnimal.cpp ./WrongCat.cpp
NAME = Animal

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