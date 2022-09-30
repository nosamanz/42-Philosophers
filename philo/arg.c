#include "philo.h"

void ft_free(t_data *data)
{
	int i = 0;
	while (i < data->n_of_philo)
	{
		pthread_detach(data->threads[i]);
		i++;
	}
	//pthread_mutex_destroy(&data->msg);
	//free(data->philo);
	//free(data);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	neg = 1;
	res = 0;
	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
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
