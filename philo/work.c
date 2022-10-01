/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:19:25 by oozcan            #+#    #+#             */
/*   Updated: 2022/10/01 17:08:53 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philos *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->r_fork]);
	msg(get_time(), "taking fork right 🥢", philo);
	pthread_mutex_lock(&data->forks[philo->l_fork]);
	msg(get_time(), "taking fork left 🥢", philo);
}

void	eating(t_philos *philo, t_data *data)
{
	take_fork(philo, data);
	msg(get_time(), "eating 🍜", philo);
	last_eat(philo);
	my_sleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
}

void	thinking(t_philos *philo)
{
	msg(get_time(), "thinking", philo);
}

void	sleeping(t_philos *philo, t_data *data)
{
	msg(get_time(), "sleeping 💤", philo);
	my_sleep(data->time_to_sleep);
}

void	*work(void *ph_ptr)
{
	t_philos	*philo;
	t_data		*data;

	philo = (t_philos *)ph_ptr;
	data = philo->data;
	if (philo->id % 2 == 0)
		my_sleep(data->time_to_eat);
	while (lc_die(data))
	{
		eating(philo, data);
		if (lc_die(data))
			sleeping(philo, data);
		if (lc_die(data))
			thinking(philo);
	}
	return (NULL);
}
