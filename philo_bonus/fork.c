/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:54:06 by oozcan            #+#    #+#             */
/*   Updated: 2022/10/06 12:26:43 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_them_all(t_data *data)
{
	int	i;
	int	r_val;

	waitpid(-1, &r_val, 0);
	if (r_val != 0)
	{
		i = 0;
		while (i < data->n_of_philo)
		{
			kill(data->philo[i].pid, 15);
			i++;
		}
		sem_close(data->sem_forks);
		sem_close(data->sem_msg);
		sem_close(data->sem_eat);
		sem_close(data->sem_death);
		sem_unlink("/forks");
		sem_unlink("/msg");
		sem_unlink("/eat");
		sem_unlink("/death");
	}
}

int	p_fork(t_data *data)
{
	t_philos	*philo;
	int			i;

	philo = data->philo;
	i = 0;
	while (i < data->n_of_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return (0);
		if (philo[i].pid == 0)
			work(&(philo[i]));
		i++;
	}
	pthread_join(philo->t_dead_check, NULL);
	kill_them_all(data);
	return (1);
}
