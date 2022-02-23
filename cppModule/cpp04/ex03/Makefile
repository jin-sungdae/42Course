CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ./main.cpp ./AMateria.cpp ./Character.cpp ./MateriaSource.cpp ./Cure.cpp ./Ice.cpp
NAME = Interface

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