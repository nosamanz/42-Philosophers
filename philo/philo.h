#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef	struct	s_data t_data;

typedef struct s_philos
{
	int l_fork;
	int r_fork;
	int id;
	int	aten;
	long long int last_eat;
	int	is_life;
	t_data	*data;
} 	t_philos;

typedef	struct	s_data
{
	pthread_mutex_t	*forks;
	pthread_t	*threads;
	pthread_mutex_t	msg;
	pthread_mutex_t	m_die;
	int	n_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_of_ph_m_eat;
	long long int start_time;
	t_philos	*philo;
	int	die;
}			t_data;


int		ft_atoi(const char *str);
void	*work(void *ph_ptr);
long	get_time();
void	error(char *str);
void	msg(long long time, char *str, t_philos *philo);
//int	check(t_philos *philo, t_data *data);
void 	ft_free(t_data *data);
int		aten(t_data *data, t_philos *philo);
int		dead(t_data *data);

#endif
