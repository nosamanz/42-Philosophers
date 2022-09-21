/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:19:25 by oozcan            #+#    #+#             */
/*   Updated: 2022/09/21 13:43:39 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(long long time)
{
	long long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(100);
}

void	take_fork(t_philos *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->r_fork]);
	msg(get_time() ,"taking fork right 🥢", philo);
	if (data->n_of_philo == 1)
	{
		my_sleep(data->time_to_die);
		msg(get_time(), "💀 DIED 💀", philo);
		data->die++;
	}
	pthread_mutex_lock(&data->forks[philo->l_fork]);
	msg(get_time() ,"taking fork left 🥢", philo);
}

void	eating(t_philos *philo, t_data *data)
{
	take_fork(philo, data);
	msg(get_time() ,"eating 🍜", philo);
	philo->last_eat = get_time();
	my_sleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
	philo->aten++;
}

void	thinking(t_philos *philo, t_data *data)
{
	msg(get_time() ,"thinking", philo);
}

void	sleeping(t_philos *philo, t_data *data)
{
	msg(get_time() ,"sleeping 💤", philo);
	my_sleep(data->time_to_sleep);
}

void	*work(void *ph_ptr)
{
	t_philos *philo;
	t_data	*data;

	philo = (t_philos *)ph_ptr;
	data = philo->data;
	data->start_time = get_time();
	if (philo->id % 2 == 0)
		my_sleep(data->time_to_eat);
	while (data->die == 0 && aten(data, philo) == 0)
	{
		if (aten(data, philo) == 0)
			eating(philo, data);
		if (aten(data, philo) == 0)
			sleeping(philo, data);
		if (aten(data, philo) == 0)
			thinking(philo, data);
	}
	return(NULL);
}
