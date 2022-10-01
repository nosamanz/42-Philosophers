/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:53:46 by oozcan            #+#    #+#             */
/*   Updated: 2022/10/01 17:26:41 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>

typedef struct s_data	t_data;

typedef struct s_philos
{
	pthread_t		t_dead_check;
	int				id;
	int				pid;
	int				aten;
	long long int	last_eat;
	t_data			*data;
}		t_philos;

typedef struct s_data
{
	t_philos		*philo;
	sem_t			*sem_forks;
	sem_t			*sem_msg;
	sem_t			*sem_death;
	sem_t			*sem_eat;
	int				n_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_ph_m_eat;
	int				die;
	int				total_eat;
	int				everyone_ate;
	long long int	start_time;
}		t_data;

int		ft_atoi(const char *str);
int		arg_check(int argc, char **argv);
void	error(char *str);
void	eating(t_philos *philo);
void	msg(long long time, char *str, t_philos *philo);
long	get_time(void);
int		p_fork(t_data *data);
void	work(void *ptr);
void	sem(t_data *data);
void	last_eat(t_philos *philo);
int		aten(t_data *data, t_philos *philo);
void	my_sleep(long long time);
void	*dead_check(void *ptr);
int		lc_check(t_philos *philo);
void	kill_them_all(t_data *data);

#endif
