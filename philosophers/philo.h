#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# define FALSE 1

struct	s_info;

typedef struct s_philo{
	int				philo_id;
	int				philo_ate;
	int				left_fork;
	int				right_fork;
	long long		last_timestamp;
	struct s_info	*info;
	pthread_t		tid;
}			t_philo;

typedef struct s_info{
	int				philo_num;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				philo_must_eat;
	int				philo_death;
	int				all_ate;
	long long		first_timestamp;
	pthread_mutex_t	eat_food;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	write;
	t_philo			philo[250];
}			t_info;

int				ft_atoi(const char *str);
void			time_check_sleep(long long time, t_info *info);
int				error_print(int flag);

int				philo_init(t_info *info, char **av);
int				philo_run(t_info *info);

long long		time_check(void);
void			sleep_time(long long time, t_info *info);
void			print_philo_act(t_info *info, int id, char *str);
void			print_philo_act_sleep(t_info *info, int id);
void			print_philo_act_think(t_info *info, int id);

void			philo_check_death(t_info *info, t_philo *philo);

void			print_philo_act_sleep(t_info *info, int id);
void			print_philo_act_think(t_info *info, int id);
void			print_philo_act(t_info *info, int id, char *str);

#endif