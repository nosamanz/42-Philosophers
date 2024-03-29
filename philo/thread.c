/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:22:32 by oozcan            #+#    #+#             */
/*   Updated: 2022/09/21 12:22:32 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_f(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_of_philo)
	{
		data->philo[i].start_time = get_time();
		pthread_create(&data->threads[i], NULL, work, &data->philo[i]);
		i++;
	}
	while (data->die == 0)
	{
		if (dead(data) == 0)
			break ;
		if (data->die != 0 || data->n_of_philo == 1)
			break ;
	}
	if (data->total_eat == data->n_of_philo)
		return (0);
	i = 0;
	while (i++ < data->n_of_philo)
		pthread_join(data->threads[i], NULL);
	ft_free(data);
	return (1);
}
