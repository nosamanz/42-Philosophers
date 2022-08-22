#include "philo.h"

void	thinking(t_philo *ph)
{
	printf("thinking\n");
}

void	eating(t_philo *ph)
{
	printf("PHILO %d is eating\n", ph->philo->pos);
}

void	sleeping(t_philo *ph)
{
	printf("sleeping\n");
}

void	*work(void *ph_ptr)
{
	t_philo *ph;
	long	time;
	int	i = 0;

	ph = (t_philo *)ph_ptr;
	ph->philo->pos = 1;
	printf("PHILO %d is eating\n", ph->philo->pos);
	ph->philo->last_eat = get_time(0);
	while (1)
	{
		// if (time >= ph->time_to_die)
		// {
		// 	printf("OLDU\n");
		// 	exit(1);
		// }
		time = get_time(time);
		//thinking(ph);
		eating(ph);
		ph->philo->pos = 1 + ph->philo->pos;
		//sleeping(ph);
	}
	return(NULL);
}
