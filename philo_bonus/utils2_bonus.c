#include "philo_bonus.h"

void	msg(long long time, char *str, t_philos *philo)
{
	sem_wait(philo->data->sem_msg);
	printf("TIME: [%lld] Philo[%d], %s\n", time - philo->start_time, philo->id, str);
	sem_post(philo->data->sem_msg);
}

void	last_eat(t_philos *philo)
{
	philo->last_eat = get_time();
	philo->aten++;
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
