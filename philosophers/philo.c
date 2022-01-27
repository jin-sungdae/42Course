#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (error_print(1));
	if (philo_init(&info, av))
		return (error_print(2));
	if (philo_run(&info))
		return (error_print(3));
	return (0);
}
