#include "philo.h"

void	p_assigment(t_philo *ph, char **argv)
{
	int i;

	i = 0;
	ph->n_of_philo = ft_atoi(argv[1]);
	ph->philo = malloc(sizeof(t_philo) * ph->n_of_philo);// filozof sayisi kadar liste
	ph->time_to_die = ft_atoi(argv[2]);
	//ph->time_to_eat = ft_atoi(argv[3]);
	//ph->time_to_sleep = ft_atoi(argv[4]);
	//if (argc == 6)
	//	ph->n_of_ph_m_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&ph->fork_left, NULL);
	pthread_mutex_init(&ph->fork_right, NULL);
	while (i <= ph->n_of_philo)
	{
		ph->philo[i].eat = 0;
		ph->philo[i].sleep = 0;
		ph->philo[i].think = 0;
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
		p_assigment(ph, argv);
		printf("NUMBER OF PHILO : %d\n", ph->n_of_philo);

		i = 0;
		while (i <= ph->n_of_philo)
		{
			pthread_create(&ph->philo[i].id, NULL, &work, &ph);
			i++;
		}
		i = 0;
		while (i++ < ph->n_of_philo)
			pthread_join(ph->philo[i].id, NULL);
		printf("end\n");
	}
	return (0);
}
