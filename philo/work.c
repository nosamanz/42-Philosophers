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
	msg(get_time() ,"taking fork left 🥢", philo);
	pthread_mutex_lock(&data->forks[philo->l_fork]);
	msg(get_time() ,"taking fork right 🥢", philo);
	pthread_mutex_lock(&data->forks[philo->r_fork]);
}

void	eating(t_philos *philo, t_data *data)
{
	take_fork(philo, data);
	msg(get_time() ,"eating 🍜", philo);
	philo->last_eat = get_time();
	my_sleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
	philo->aten++;
}

void	thinking(t_philos *philo, t_data *data)
{
	msg(get_time() ,"thinking", philo);
}

void	sleeping(t_philos *philo, t_data *data)
{
	msg(get_time() ,"sleeping 💤", philo);
	my_sleep(data->time_to_sleep);
}

void	*work(void *ph_ptr)
{
	t_philos *philo;
	t_data	*data;

	philo = (t_philos *)ph_ptr;
	data = philo->data;
	data->start_time = get_time();
	long long int time = 0;
	if (philo->id % 2 == 0)
		my_sleep(data->time_to_eat);
	while (data->die == 0 && aten(data, philo) == 0)
	{
		if (get_time() - philo->last_eat > data->time_to_die && philo->last_eat > 0)
		{
			time = get_time();
			msg(time, "DEAD\n\n\n", philo);
			data->philo->is_life = 0;
			data->die++;
			break;
		}
		eating(philo, data);
		sleeping(philo, data);
		thinking(philo, data);
	}
	return(NULL);
}
