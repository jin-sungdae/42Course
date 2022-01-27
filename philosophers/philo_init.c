#include "philo.h"

int	mutex_init(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&(info->fork[i]), NULL))
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&(info->write), NULL))
		return (FALSE);
	if (pthread_mutex_init(&(info->eat_food), NULL))
		return (FALSE);
	return (0);
}

int	philosophers_init(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		info->philo[i].philo_id = i;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->philo_num;
		info->philo[i].philo_ate = 0;
		info->philo[i].last_timestamp = 0;
		info->philo[i].info = info;
		i++;
	}
	return (0);
}

int	check_zero_param(t_info *info)
{
	if (info->philo_num <= 0)
		return (FALSE);
	if (info->time_death <= 60)
		return (FALSE);
	if (info->time_eat <= 60)
		return (FALSE);
	if (info->time_sleep <= 60)
		return (FALSE);
	if (info->philo_num >= 200)
		return (FALSE);
	return (0);
}

void	philo_init_atoi(t_info *info, char **av)
{
	info->philo_num = ft_atoi(av[1]);
	info->time_death = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->all_ate = 0;
	info->philo_death = 0;
}

int	philo_init(t_info *info, char **av)
{
	philo_init_atoi(info, av);
	if (check_zero_param(info))
		return (FALSE);
	if (av[5])
	{
		info->philo_must_eat = ft_atoi(av[5]);
		if (info->philo_must_eat <= 0)
			return (FALSE);
	}
	else
		info->philo_must_eat = -1;
	if (mutex_init(info))
		return (FALSE);
	philosophers_init(info);
	return (0);
}
