#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct	s_status
{
	long	last_eat;
	int		eat;
	int		sleep;
	int		think;
	int		pos;
}				t_status;

typedef	struct	s_philo
{
	pthread_t	*philo;
	pthread_mutex_t	*fork;
	int	left_fork;
	int right_fork;
	int	first_time;
	int	n_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_of_ph_m_eat;
	t_status	*philo_s;
}			t_philo;


int	ft_atoi(const char *str);
void	*work(void *ph_ptr);
long	get_time(int time);

#endif
