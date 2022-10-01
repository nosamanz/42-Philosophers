/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:53:56 by oozcan            #+#    #+#             */
/*   Updated: 2022/10/01 17:42:43 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	one_philo(t_philos *philo)
{
	sem_wait(philo->data->sem_forks);
	msg(get_time(), "has taken a fork", philo);
	my_sleep(philo->data->time_to_die);
	msg(get_time(), "died", philo);
	exit(1);
}

void	eating(t_philos *philo)
{
	sem_wait(philo->data->sem_forks);
	msg(get_time(), "has taken a fork", philo);
	sem_wait(philo->data->sem_forks);
	msg(get_time(), "has taken a fork", philo);
	sem_wait(philo->data->sem_eat);
	sem_wait(philo->data->sem_death);
	philo->last_eat = get_time();
	philo->aten++;
	sem_post(philo->data->sem_death);
	msg(get_time(), "eating", philo);
	sem_post(philo->data->sem_eat);
	my_sleep(philo->data->time_to_eat);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
}

void	sleeping(t_philos *philo)
{
	msg(get_time(), "sleeping", philo);
	my_sleep(philo->data->time_to_sleep);
}

void	thinking(t_philos *philo)
{
	msg(get_time(), "thinking", philo);
}

void	work(void *ptr)
{
	t_philos	*philo;

	philo = (t_philos *)ptr;
	philo->data->start_time = get_time();
	if (philo->data->n_of_philo == 1)
		one_philo(philo);
	pthread_create(&(philo->t_dead_check), NULL, dead_check, philo);
	if (philo->id % 2 == 0)
		my_sleep(philo->data->time_to_eat);
	while (1)
	{
		if (lc_check(philo) != 1)
			break ;
		eating(philo);
		if (lc_check(philo) != 1)
			break ;
		sleeping(philo);
		if (lc_check(philo) != 1)
			break ;
		thinking(philo);
	}
	pthread_join(philo->t_dead_check, NULL);
	exit(0);
}
