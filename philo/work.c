#include "philo.h"

void	my_sleep(long long time)
{
	long long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(100);
}

void	take_fork(t_philos *philo, t_data *data)
{
	printf("[%d]taking fork left 🥢 r=%d l=%d\n", philo->id, philo->r_fork, philo->l_fork);
	pthread_mutex_lock(&data->forks[philo->l_fork]);
	printf("[%d]taking fork right 🥢 \n", philo->id);
	pthread_mutex_lock(&data->forks[philo->r_fork]);
}

void	eating(t_philos *philo, t_data *data)
{
	take_fork(philo, data);
	philo->last_eat = get_time();
	msg("eating 🍜", philo);
	my_sleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
	philo->aten++;
}

void	thinking(t_philos *philo, t_data *data)
{
	printf("thinking\n");
}

void	sleeping(t_philos *philo, t_data *data)
{
	long long int time = 0;
	time = get_time();
	printf("TIME: [%lld] Philo[%d] is sleeping 💤\n", time - data->start_time, philo->id);
	usleep(data->time_to_sleep);
}

void	*work(void *ph_ptr)
{
	t_philos *philo;
	t_data	*data;

	philo = (t_philos *)ph_ptr;
	data = philo->data;
	data->start_time = get_time();
	if (philo->id % 2 == 0)
		my_sleep(data->time_to_eat);
	while (1)
	{
		if (philo->aten == data->n_of_ph_m_eat)
			break;
		eating(philo, data);
		sleeping(philo, data);
		thinking(philo, data);
	}
	return(NULL);
}
