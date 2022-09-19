#include "philo.h"

int	thread_f(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_of_philo)
	{
		pthread_create(&data->threads[i], NULL, work, &data->philo[i]);
		i++;
	}
	while (data->die == 0 || aten(data, data->philo) == 0)
	{
		if (dead(data) == 0 || aten(data, data->philo) == 0)
		{
			ft_free(data);
			return (0);
		}
	}
	i = 0;
	while (i++ < data->n_of_philo)
		pthread_join(data->threads[i], NULL);
	printf("The End\n");
	return (1);
}
