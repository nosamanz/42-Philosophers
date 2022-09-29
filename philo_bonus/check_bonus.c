#include "philo_bonus.h"

void	*dead_check(void *ptr)
{
	t_philos *philo;

	philo = (t_philos *)ptr;
	while (1)
	{
		if (get_time() - philo->last_eat > philo->data->time_to_die && philo->last_eat != 0 && philo->data->die <= 1)
		{
			philo->data->die++;
			sem_wait(philo->data->sem_death);
			my_sleep(5);
			msg(get_time(), "DEAD", philo);
			sem_post(philo->data->sem_death);
			exit(1);
		}
	}
	return NULL;
}

int	lc_check(t_philos *philo)
{
	if (get_time() - philo->last_eat > philo->data->time_to_die && philo->last_eat != 0)
	{
		return (0);
	}
	return (1);
}

int	is_arg_zero(char c)
{
	if (c == '0')
	{
		error("Arg must be greater than 0");
		return (1);
	}
	return (0);
}

int	arg_check(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (is_arg_zero(argv[i][j]))
			return (0);
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9'))
				j++;
			else if (j == 0 && argv[i][j] == '+' && argv[i][j + 1] > 32)
				j++;
			else
				return (0);
		}
		j = 0;
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
