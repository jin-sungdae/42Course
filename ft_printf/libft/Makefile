NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES= ft_atoi ft_bzero ft_calloc ft_isdigit ft_isalnum ft_isalpha ft_isascii \
	ft_isprint ft_itoa ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memmove \
	ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split \
	ft_strchr ft_strdup ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi \
	ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper \
	ft_putchar ft_putnbr ft_itoa ft_putstr ft_itoa_base ft_strcat ft_strcpy ft_strjoin \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))


OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all
