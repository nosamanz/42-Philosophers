/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:06:53 by oozcan            #+#    #+#             */
/*   Updated: 2022/09/28 12:38:41 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_of_philo);
	while (i < data->n_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->msg, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	pthread_mutex_init(&data->m_check, NULL);
}

void	last_philo(t_data *data, int i)
{
	data->philo[i].data = data;
	data->philo[i].id = i + 1;
	data->philo[i].l_fork = 0;
	data->philo[i].r_fork = i;
	data->philo[i].aten = 0;
}

void	p_assigment(t_data *data, int argc, char **argv)
{
	int i;
	i = 0;

	data->n_of_philo = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philos) * data->n_of_philo);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->total_eat = 0;
	data->die = 0;
	data->n_of_ph_m_eat = -1;
	if (argc == 6)
		data->n_of_ph_m_eat = ft_atoi(argv[5]);
	mutex_init(data);
	i = 0;
	while (i < data->n_of_philo - 1 && data->n_of_philo > 1)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].r_fork = i;
		data->philo[i].l_fork = i + 1;
		data->philo[i].aten = 0;
		i++;
	}
	last_philo(data, i);
 }

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		t_data	*data;

		if (!arg_check(argc, argv))
		{
			error("Arg Error! Invalid Arg");
			return (0);
		}
		data = malloc(sizeof(t_data));
		data->threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
		p_assigment(data, argc, argv);
		thread_f(data);
	}
	else
		error("Arg Error!");
	return (0);
}
