#include "philo.h"

void	take_fork(t_philo *ph)
{
	printf("taking fork\n");
	//pthread_mutex_lock();
	//pthread_mutex_lock();
}

void	eating(t_philo *ph)
{
	take_fork(ph);
	printf("PHILO is eating\n");
	usleep(ph->time_to_die);
	printf("PHILO is ate\n");
}

void	thinking(t_philo *ph)
{
	printf("thinking\n");
}

void	sleeping(t_philo *ph)
{
	printf("sleeping\n");
}

void	*work(void *ph_ptr)
{
	t_philo *ph;
	int	time = 0;
	int	i = 0;

	ph = (t_philo *)ph_ptr;
	time = get_time(time);
	//printf("FIRST TIME %d\n", time);
	while (1)
	{
		//printf("Other TIME %ld\n", get_time(time));
		eating(ph);
		pause();
	}
	return(NULL);
}
