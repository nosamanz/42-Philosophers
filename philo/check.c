#include "philo.h"

int	dead(t_data *data)
{
	int i = 0;

	while (i < data->n_of_philo)
	{
		if (data->philo[i].last_eat != 0 && (get_time() - data->philo[i].last_eat) > data->time_to_die)
		{
			if (data->philo[i].is_life != 0)
			{
				msg(get_time(), "💀 DIED 💀", data->philo);
				data->philo[i].is_life = 0;
				data->die = 1;
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	aten(t_data *data, t_philos *philo)
{
	if (philo->aten == data->n_of_ph_m_eat && data->n_of_ph_m_eat > 0)
	{
		return (1);
	}
	return (0);
}

int	is_arg_zero(char c)
{
	if (c == '0')
	{
		printf("Arg must be greater than 0\n");
		return (1);
	}
	return (0);
}

int	arg_check(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argv[i][j])
	{
		if (is_arg_zero(argv[i][j]))
			return (1);
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else if (argv[i][j] == '+')
				j++;
			else
			{
				printf("Arg Error! Arg is not number or is not a positive\n");
				return (1);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
