MMSPATH = ./minilibx
CLFLAGS = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
SRCS = ./src/load_image.c ./src/raycasting.c ./src/description.c ./src/description1.c ./src/description2.c  ./src/key.c ./src/key1.c ./src/floar_ceiling.c ./src/map_checker.c \
 	./src/map_player.c  ./src/memory.c ./src/libft1.c ./src/libft2.c ./src/libft3.c ./src/map_checker_utils.c \
 	./main.c

NAME = cub3d
OBJS = ${SRCS:.c=.o}
OBJ = ${GNL:.c=.o}

all : ${NAME}

.c.o : ${SRCS} ${GNL}
	${CC} ${CFLAGS} -c -o $@ $<

${NAME} : ${OBJS} ${OBJ}
	gcc $(FLAGS) -o  ${NAME} ${OBJ} ${OBJS} -L $(MMSPATH) $(CLFLAGS)

clean :
	rm -rf $(OBJ) ${OBJS} 

fclean : clean
	rm -rf ${NAME}

re : fclean all


