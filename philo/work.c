#include "philo.h"

void	thinking(t_philo *ph)
{
	printf("thinking\n");
}

void	eating(t_philo *ph)
{
	printf("eating\n");
}

void	sleeping(t_philo *ph)
{
	printf("sleeping\n");
}

void	*work(void *ph_ptr)
{
	t_philo *ph;
	long	time;

	ph = (t_philo *)ph_ptr;

	while (1)
	{
		if (time >= ph->time_to_die)
		{
			printf("OLDU\n");
			exit(1);
		}
		time = get_time(time);
		usleep(10000);
		thinking(ph);
		eating(ph);
		sleeping(ph);
	}
	return(NULL);
}
