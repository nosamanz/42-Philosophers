#include "philo_bonus.h"

void	msg(long long time, char *str, int id, t_data *data)
{
	sem_wait(data->sem_msg);
	printf("TIME: [%lld] Philo[%d], %s\n", time - data->philo[id - 1].start_time, id, str);
	sem_post(data->sem_msg);
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
