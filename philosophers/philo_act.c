#include "philo.h"

void	print_philo_act_sleep(t_info *info, int id)
{
	pthread_mutex_lock(&(info->write));
	if (!(info->philo_death))
	{
		printf("%lli ms : ", time_check() - info->first_timestamp);
		printf("%d %s\n", id + 1, "is thinking");
	}
	pthread_mutex_unlock(&(info->write));
	return ;
}

void	print_philo_act_think(t_info *info, int id)
{
	time_check_sleep(info->time_sleep, info);
	pthread_mutex_lock(&(info->write));
	if (!(info->philo_death))
	{
		printf("%lli ms : ", time_check() - info->first_timestamp);
		printf("%d %s\n", id + 1, "is sleeping");
	}
	pthread_mutex_unlock(&(info->write));
	return ;
}

void	print_philo_act(t_info *info, int id, char *str)
{
	pthread_mutex_lock(&(info->write));
	if (!(info->philo_death))
	{
		printf("%lli ms : ", time_check() - info->first_timestamp);
		printf("%d %s\n", id + 1, str);
	}
	pthread_mutex_unlock(&(info->write));
	return ;
}
