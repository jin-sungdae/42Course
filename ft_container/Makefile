CXX		= clang++
RM		= rm -rf
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

NAME = ft_container.out
VECTOR_NAME = diff/diff_vector
MAP_NAME =	diff/diff_map
STACK_NAME = diff/diff_stack
MK_DIR = mkdir -p out diff objs
all	: $(VECTOR_NAME) $(MAP_NAME) $(STACK_NAME)

vector:	$(VECTOR_NAME)

$(VECTOR_NAME) :
				$(MK_DIR)
				$(CXX) $(CXXFLAGS) -o objs/ft_vector.o -DTESTED_NAMESPACE=ft -c ./vector/vector_main.cpp
				$(CXX) $(CXXFLAGS) -o objs/std_vector.o -DTESTED_NAMESPACE=std -c ./vector/vector_main.cpp
				$(CXX) $(CXXFLAGS) -o out/ft_vector.out objs/ft_vector.o
				$(CXX) $(CXXFLAGS) -o out/std_vector.out objs/std_vector.o
				./out/ft_vector.out >out/ft_data
				./out/std_vector.out >out/std_data
				diff -d out/ft_data out/std_data 2>/dev/null 1>diff/diff_vector || exit 0
				rm out/ft_data out/std_data

map: $(MAP_NAME)
$(MAP_NAME) :
				$(MK_DIR)
				$(CXX) $(CXXFLAGS) -o objs/ft_map.o -DTESTED_NAMESPACE=ft -c ./map/map_main.cpp
				$(CXX) $(CXXFLAGS) -o objs/std_map.o -DTESTED_NAMESPACE=std -c ./map/map_main.cpp
				$(CXX) $(CXXFLAGS) -o out/ft_map.out objs/ft_map.o
				$(CXX) $(CXXFLAGS) -o out/std_map.out objs/std_map.o
				./out/ft_map.out >out/ft_data
				./out/std_map.out >out/std_data
				diff -d out/ft_data out/std_data 2>/dev/null 1>diff/diff_map || exit 0
				rm out/ft_data out/std_data

stack: $(STACK_NAME)
$(STACK_NAME) :
				$(MK_DIR)
				$(CXX) $(CXXFLAGS) -o objs/ft_stack.o -DTESTED_NAMESPACE=ft -c ./stack/stack_main.cpp
				$(CXX) $(CXXFLAGS) -o objs/std_stack.o -DTESTED_NAMESPACE=std -c ./stack/stack_main.cpp
				$(CXX) $(CXXFLAGS) -o out/ft_stack.out objs/ft_stack.o
				$(CXX) $(CXXFLAGS) -o out/std_stack.out objs/std_stack.o
				./out/ft_stack.out >out/ft_data
				./out/std_stack.out >out/std_data
				diff -d out/ft_data out/std_data 2>/dev/null 1>diff/diff_stack || exit 0
				rm out/ft_data out/std_data


clean:
				rm -rf objs

fclean:			clean
				$(RM) $(NAME)
				$(RM) out/ft_vector.out out/ft_map.out out/ft_stack.out \
					out/std_vector.out out/std_map.out out/std_stack.out \
					diff/diff_vector diff/diff_map diff/diff_stack \
					diff out
re:				fclean $(NAME)

.PHONY:			all clean fclean re vector stack map


