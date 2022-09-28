/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:19:17 by oozcan            #+#    #+#             */
/*   Updated: 2022/09/28 12:32:00 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(long long time, char *str, t_philos *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	printf("TIME: [%lld] Philo[%d], %s\n", time - philo->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->msg);
}

void	die(t_data *data)
{
	data->die++;
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
