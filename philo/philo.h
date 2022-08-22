#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct	s_status
{
	pthread_t	id;
	long	last_eat;
	int	eat;
	int	sleep;
	int	think;
}				t_status;

typedef	struct	s_philo
{
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
	int	n_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_of_ph_m_eat;
	t_status	*philo;
}			t_philo;


int	ft_atoi(const char *str);
void	*work(void *ph_ptr);
long	get_time();

#endif
