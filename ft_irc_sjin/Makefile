NAME = ircserv
CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
DIR = ./
SRCS = main.cpp\
		User/User.cpp User/UserManager.cpp\
		Channel/Channel.cpp Channel/ChannelManager.cpp\
		Network/Network.cpp\
		Server/Server.cpp\
		Logger/Logger.cpp\
		Command/Cjoin.cpp Command/Ckick.cpp Command/Cnick.cpp Command/Cpart.cpp Command/Cpass.cpp Command/Cnotice.cpp\
		Command/Cping.cpp Command/Cpong.cpp Command/Cquit.cpp Command/Cuser.cpp Command/Cprivmsg.cpp Command/Cmode.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) -o $(NAME) $^
%.o : %.cpp
	$(CPP) $(FLAGS) -o $@ -c $<
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : 
	make fclean
	make all
.PHONY : all clean fclean re 
