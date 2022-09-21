/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:19:17 by oozcan            #+#    #+#             */
/*   Updated: 2022/09/21 14:00:12 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(long long time, char *str, t_philos *philo)
{
	long long int	tm;

	tm = 0;
	pthread_mutex_lock(&philo->data->msg);
	if (philo->data->die > 0)
		return;
	tm = time - philo->data->start_time;
	if (tm >= 0)
		printf("TIME: [%lld] Philo[%d], %s\n", time - philo->data->start_time, philo->id, str);
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
