#include "philo.h"

void	philo_eat(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->fork[philo->left_fork]));
	print_philo_act(info, philo->philo_id, "take left fork");
	pthread_mutex_lock(&(info->fork[philo->right_fork]));
	print_philo_act(info, philo->philo_id, "take right fork");
	pthread_mutex_lock(&(info->eat_food));
	print_philo_act(info, philo->philo_id, "eating");
	philo->last_timestamp = time_check();
	pthread_mutex_unlock(&(info->eat_food));
	time_check_sleep(info->time_eat, info);
	(philo->philo_ate)++;
	pthread_mutex_unlock(&(info->fork[philo->right_fork]));
	pthread_mutex_unlock(&(info->fork[philo->left_fork]));
}

void	*pthread_run(void *param)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)param;
	info = philo->info;
	if (philo->philo_id % 2)
		usleep(1500);
	while (!(info->philo_death))
	{
		philo_eat(philo);
		if (info->all_ate)
			break ;
		print_philo_act_think(info, philo->philo_id);
		print_philo_act_sleep(info, philo->philo_id);
	}
	return (NULL);
}

int	philo_run(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = info->philo;
	info->first_timestamp = time_check();
	while (i < info->philo_num)
	{
		if (pthread_create(&(philo[i].tid), NULL, pthread_run, &(philo[i])))
			return (FALSE);
		philo[i].last_timestamp = time_check();
		i++;
	}
	philo_check_death(info, info->philo);
	return (0);
}
