#include "philo_bonus.h"

void	eating(t_philos *philo)
{
	msg(get_time(), "taking fork RIGHT", philo);
	sem_wait(philo->data->sem_forks);
	msg(get_time(), "taking fork LEFT", philo);
	sem_wait(philo->data->sem_forks);
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
	if (philo->id % 2 == 1)
		my_sleep(philo->data->time_to_eat);
	pthread_create(&(philo->t_dead_check), NULL, dead_check, philo);
	while (philo->data->die != 1)
	{
		//if (dead_check(philo) == 1)
		eating(philo);
		//if (dead_check(philo) == 1)
		sleeping(philo);
		//if (dead_check(philo) == 1)
		thinking(philo);
	}
	pthread_join(philo->t_dead_check, NULL);
	if (philo->data->die == 1)
		exit(1);
	exit(0);
}
