#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_data t_data;

typedef struct s_philos
{
	pthread_t	t_dead_check;
	int				id;
	int				pid;
	int				aten;
	long long int	start_time;
	long long int	last_eat;
	t_data	*data;
}		t_philos;

typedef struct s_data
{
	t_philos *philo;
	sem_t	*sem_forks;
	sem_t	*sem_msg;
	//sem_t	*sem_death;
	int	n_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_of_ph_m_eat;
	int	die;
	int	total_eat;
}		t_data;

int		ft_atoi(const char *str);
int		arg_check(int argc, char **argv);
void	error(char *str);
void	eating(t_philos *philo);
void	msg(long long time, char *str, t_philos *philo);
long	get_time();
int		p_fork(t_data *data);
void	work(void *ptr);
void	sem(t_data *data);
void	last_eat(t_philos *philo);
void	my_sleep(long long time);
void	*dead_check(void *ptr);

#endif
