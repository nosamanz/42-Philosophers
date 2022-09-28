#include "philo_bonus.h"

void	kill_them_all(t_data *data)
{
	int	i;
	int	r_val;

	waitpid(-1, &r_val, 0);//////////////////////////////
	if (r_val != 0)
	{
		printf("seni gidi\n");
		while (i < data->n_of_philo)
		{
			kill(data->philo[i].pid, 15);
			i++;
		}
	}
}

int	p_fork(t_data *data)
{
	t_philos *philo;
	int	i;

	philo = data->philo;
	i = 0;
	while (i < data->n_of_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return (0);
		if (philo[i].pid == 0)
		{
			data->philo[i].start_time = get_time();
			work(&(philo[i]));
		}
		i++;
	}
	kill_them_all(data);
	return (1);
}
