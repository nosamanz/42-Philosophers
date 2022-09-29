#include "philo_bonus.h"

void	eating(t_philos *philo)
{
	sem_wait(philo->data->sem_forks);
	msg(get_time(), "taking fork RIGHT", philo);
	sem_wait(philo->data->sem_forks);
	msg(get_time(), "taking fork LEFT", philo);
	msg(get_time(), "eating", philo);
	last_eat(philo);
	my_sleep(philo->data->time_to_eat);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
}

void	sleeping(t_philos *philo)
{
	msg(get_time(), "sleeping", philo);
	my_sleep(philo->data->time_to_sleep);
}

void	thinking(t_philos *philo)
{
	msg(get_time(), "thinking", philo);
}

void	work(void *ptr)
{
	t_philos *philo;

	philo = (t_philos *)ptr;
	if (philo->id % 2 == 0)
		my_sleep(philo->data->time_to_eat);
	pthread_create(&(philo->t_dead_check), NULL, dead_check, philo);
	while (1)
	{
		printf("UFf!\n");
		if (lc_check(philo) != 1)
			break;
		eating(philo);
		if (lc_check(philo) != 1)
			break;
		sleeping(philo);
		if (lc_check(philo) != 1)
			break;
		thinking(philo);
	}
	pthread_join(philo->t_dead_check, NULL);
	exit(0);
}
