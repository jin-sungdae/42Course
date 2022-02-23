CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ./main.cpp ./Base.cpp ./A.cpp ./B.cpp ./C.cpp 
NAME = DownCasting

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