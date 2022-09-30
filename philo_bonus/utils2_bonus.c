#include "philo_bonus.h"

void	msg(long long time, char *str, t_philos *philo)
{
	sem_wait(philo->data->sem_msg);
	//sem_wait(philo->data->sem_death);
	if (philo->data->die == 0)
		printf("TIME: [%lld] Philo[%d], %s\n", time - philo->data->start_time, philo->id, str);
	sem_post(philo->data->sem_msg);
	sem_post(philo->data->sem_msg);
}

void	ft_free(t_data *data)
{
	//sem_unlink();
	pthread_detach(data->philo->t_dead_check);
}

void	error(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}
