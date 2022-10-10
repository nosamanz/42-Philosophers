/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:54:15 by oozcan            #+#    #+#             */
/*   Updated: 2022/10/10 12:15:07 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	msg(long long time, char *str, t_philos *philo)
{
	sem_wait(philo->data->sem_msg);
	if (philo->data->die == 0)
		printf("%lld %d %s\n", \
				time - philo->data->start_time, philo->id, str);
	sem_post(philo->data->sem_msg);
	//sem_post(philo->data->sem_msg);
}

void	error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}
