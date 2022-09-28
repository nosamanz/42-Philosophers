#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_data t_data;

typedef struct s_philos
{
	t_data	*data;
	int	id;
	int	start_time;
}		t_philos;

typedef struct s_data
{
	sem_t	*semaphore;
	sem_t	*sem_msg;
	int	n_of_philo;
	t_philos *philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_of_ph_m_eat;
	int	f_id;
}		t_data;

int		ft_atoi(const char *str);
int		arg_check(int argc, char **argv);
void	error(char *str);
void	msg(long long time, char *str, int id, t_data *data);
long	get_time();
void	p_fork(t_data *data);
void	work(t_philos *philo, int i);
void	sem(t_data *data);

#endif
