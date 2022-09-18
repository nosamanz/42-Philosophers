#include "philo.h"

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
