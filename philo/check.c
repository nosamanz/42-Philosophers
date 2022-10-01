/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:19:50 by oozcan            #+#    #+#             */
/*   Updated: 2022/10/01 17:02:10 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_check(t_data *data, int i)
{
	pthread_mutex_lock(&data->m_eat);
	if (data->philo[i].last_eat != 0 && \
			(get_time() - data->philo[i].last_eat) > data->time_to_die)
	{
		pthread_mutex_unlock(&data->m_eat);
		return (0);
	}
	pthread_mutex_unlock(&data->m_eat);
	return (1);
}

int	dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_of_philo)
	{
		if (!time_check(data, i) || (data->n_of_philo == 1))
		{
			if (data->n_of_philo == 1)
			{
				my_sleep(data->time_to_die);
				msg(get_time(), "💀 DIED 💀", data->philo);
				return (0);
			}
			printf("TIME: [%lld] Philo[%d], 💀 DIED 💀\n", \
					get_time() - data->philo[i].start_time, data->philo[i].id);
			pthread_mutex_lock(&data->m_die);
			die(data);
			pthread_mutex_unlock(&data->m_die);
			return (0);
		}
		i++;
	}
	return (1);
}

int	lc_die(t_data *data)
{
	pthread_mutex_lock(&data->m_die);
	if (data->die > 0)
	{
		pthread_mutex_unlock(&data->m_die);
		return (0);
	}
	pthread_mutex_unlock(&data->m_die);
	return (1);
}

int	lc_aten(t_data *data, t_philos *philo)
{
	pthread_mutex_lock(&data->m_eat);
	if (philo->aten == data->n_of_ph_m_eat && data->n_of_ph_m_eat > 0)
	{
		data->total_eat++;
		if (data->total_eat == data->n_of_ph_m_eat)
		{
			pthread_mutex_unlock(&data->m_eat);
			return (1);
		}
		pthread_mutex_unlock(&data->m_eat);
		return (0);
	}
	pthread_mutex_unlock(&data->m_eat);
	return (0);
}
