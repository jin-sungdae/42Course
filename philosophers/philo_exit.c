#include "philo.h"

void	philo_exit(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i++ < info->philo_num)
		pthread_join(philo[i].tid, NULL);
	i = 0;
	while (i++ < info->philo_num)
		pthread_mutex_destroy(&(info->fork[i]));
	pthread_mutex_destroy(&(info->write));
}

void	check_must_eat_death(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (info->philo_must_eat != -1 && i < info->philo_num
		&& philo[i].philo_ate >= info->philo_must_eat)
		i++;
	if (i == info->philo_num)
		info->all_ate = 1;
}

void	philo_check_death(t_info *info, t_philo *philo)
{
	int	i;

	while (!info->all_ate)
	{
		i = 0;
		while (i++ < info->philo_num && !(info->philo_death))
		{
			pthread_mutex_lock(&(info->eat_food));
			if (time_check() - philo[i].last_timestamp > info->time_death)
			{
				print_philo_act(info, i - 1, "death");
				info->philo_death = 1;
			}
			pthread_mutex_unlock(&(info->eat_food));
			usleep(100);
		}
		if (info->philo_death)
			break ;
		check_must_eat_death(info, philo);
	}
	philo_exit(info, philo);
}
