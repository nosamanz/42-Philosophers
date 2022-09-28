#include "philo_bonus.h"

void	p_fork(t_data *data)
{
	t_philos *philo;
	int i;

	i = 0;
	philo = malloc(sizeof(t_philos) * data->n_of_philo);
	while (i < data->n_of_philo)
	{
		if (data->f_id != 0)
			data->f_id = fork();
		if (data->f_id == 0)
		{
			data->philo[i].start_time = get_time();
			work(&philo[i], i + 1);
		}
		i++;
	}
}
