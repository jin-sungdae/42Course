#include "libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	write(fd, str, ft_strlen((char*)str));
}
