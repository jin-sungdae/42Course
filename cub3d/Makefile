MMSPATH = ./minilibx
CLFLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
SRC = ./src/load_image.c ./src/raycasting.c ./src/description.c ./src/description1.c ./src/description2.c  ./src/key.c ./src/key1.c ./src/floar_ceiling.c ./src/map_checker.c \
	./src/map_player.c  ./src/memory.c ./src/libft1.c ./src/libft2.c ./src/libft3.c ./src/map_checker_utils.c \
	./src/free_memory.c

a.out : 
	gcc $(FLAGS) -L $(MMSPATH) $(CLFLAGS) $(GNL) $(SRC) main.c

clean :
	rm -rf a.out
