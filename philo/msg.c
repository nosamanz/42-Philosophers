#include "philo.h"

void	msg(long long time, char *str, t_philos *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	printf("TIME: [%lld] Philo[%d], %s\n", time - philo->data->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->msg);
}

void	error(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}
