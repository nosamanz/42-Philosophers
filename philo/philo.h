/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:19:36 by oozcan            #+#    #+#             */
/*   Updated: 2022/10/01 17:20:57 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philos
{
	int				l_fork;
	int				r_fork;
	int				id;
	int				aten;
	int				time_to_die;
	long long int	last_eat;
	long long int	start_time;
	t_data			*data;
}	t_philos;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	pthread_mutex_t	m_die;
	pthread_mutex_t	msg;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_check;
	int				n_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_ph_m_eat;
	int				total_eat;
	int				die;
	t_philos		*philo;
}			t_data;

int		ft_atoi(const char *str);
int		arg_check(int argc, char **argv);
int		thread_f(t_data *data);
void	*work(void *ph_ptr);
long	get_time(void);
void	my_sleep(long long time);
void	error(char *str);
void	msg(long long time, char *str, t_philos *philo);
void	ft_free(t_data *data);
int		lc_aten(t_data *data, t_philos *philo);
int		lc_die(t_data *data);
int		dead(t_data *data);
void	last_eat(t_philos *philo);
void	die(t_data *data);

#endif
