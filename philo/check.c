#include "philo.h"

int	is_dead(t_data *data)
{
	int i = 0;

	while (i < data->n_of_philo)
	{
		pthread_mutex_lock(&data->m_die);
		if (data->philo[i].last_eat != 0 && (get_time() - data->philo[i].last_eat) > data->time_to_die)
		{
			if (data->philo[i].is_life == 1)
			{
				msg(get_time(), "DEAD", data->philo);
				data->philo[i].is_life = 0;
				data->die = 1;
			}
			return 1;
		}
		pthread_mutex_unlock(&data->m_die);
		i++;
	}
}

int	aten(t_data *data, t_philos *philo)
{
	if (philo->aten == data->n_of_ph_m_eat && data->n_of_ph_m_eat > 0)
	{
		printf("DOYDU\n");
		return (1);
	}
	return (0);
}

void ft_free(t_data *data)
{
	int i = 0;
	while (i < data->n_of_philo)
	{
		pthread_detach(data->threads[i]);
		i++;
	}
}
