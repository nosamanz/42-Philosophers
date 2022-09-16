#include "philo.h"

void	msg(char *str, t_philos *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	printf("TIME: [%lld] Philo[%d], %s\n", philo->last_eat - data->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->msg);
}

void	error(char *str)
{
	printf("%s\n", str);
}
