#include "philo.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i++] - '0';
	}
	if (i > 19)
		return (0);
	return (number * sign);
}

long long	time_check(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return ((val.tv_sec * 1000) + (val.tv_usec / 1000));
}

void	time_check_sleep(long long time, t_info *info)
{
	long long	i;

	i = time_check();
	while (!(info->philo_death))
	{
		if (time_check() - i >= time)
			break ;
		usleep(50);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error_print(int flag)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "Wrong argument Error\n";
	str2 = "INIT Mutex Error\n";
	str3 = "Something Wrong Error\n";
	if (flag == 1)
		write(2, str1, ft_strlen(str1));
	else if (flag == 2)
		write(2, str2, ft_strlen(str2));
	else if (flag == 3)
		write(2, str3, ft_strlen(str3));
	return (0);
}
