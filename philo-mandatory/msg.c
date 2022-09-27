/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:19:17 by oozcan            #+#    #+#             */
/*   Updated: 2022/09/27 18:08:36 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(long long time, char *str, t_philos *philo)
{
	pthread_mutex_lock(&philo->data->msg);
	printf("TIME: [%lld] Philo[%d], %s\n", time - philo->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->msg);
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
