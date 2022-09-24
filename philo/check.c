/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:19:50 by oozcan            #+#    #+#             */
/*   Updated: 2022/09/24 14:35:20 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		data->total_eat++;
		if (data->total_eat == data->n_of_ph_m_eat)
		{
			printf("tum philolar yedi\n");
			return (1);
		}
		return (0);
	}
	return (0);
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
