#include "philo.h"

void	forks(t_philo *ph)
{
	int	i;

	i = 0;
	ph->fork = malloc(sizeof(pthread_t) * ph->n_of_philo);
	while (i < ph->n_of_philo)
	{
		pthread_mutex_init(&ph->fork[i], NULL);
		i++;
	}
}

void	p_assigment(t_philo *ph, char **argv)
{
	int i;

	i = 0;
	ph->n_of_philo = ft_atoi(argv[1]);
	printf("n_of philo %d\n", ph->n_of_philo);
	ph->philo_s = malloc(sizeof(t_philo) * ph->n_of_philo);// filozof sayisi kadar liste (status)
	ph->time_to_die = ft_atoi(argv[2]);
	ph->time_to_eat = ft_atoi(argv[3]);
	// ph->time_to_sleep = ft_atoi(argv[4]);
	// if (argc == 6)
	// 	ph->n_of_ph_m_eat = ft_atoi(argv[5]);
	forks(ph);
	while (i < ph->n_of_philo)
	{
		ph->philo_s[i].eat = 0;
		ph->philo_s[i].sleep = 0;
		ph->philo_s[i].think = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		t_philo	*ph;
		int	i;

		ph = malloc(sizeof(t_philo));
		ph->philo = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
		p_assigment(ph, argv);
		i = 0;
		while (i < ph->n_of_philo)
		{
			ph->philo_s->pos = i;
			pthread_create(&ph->philo[i], NULL, &work, (void *)&ph->philo[i]);
			i++;
		}
		i = 0;
		while (i++ < ph->n_of_philo)
			pthread_join(ph->philo[i], NULL);
		printf("end\n");
	}
	return (0);
}
