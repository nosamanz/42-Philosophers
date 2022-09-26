#include "philo.h"

void	die(t_data *data)
{
	data->die++;
}

void	last_eat(t_philos *philo)
{
	philo->last_eat = get_time();
	philo->aten++;
}
