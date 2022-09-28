#include "philo_bonus.h"

void	sem(t_data *data)
{
	sem_unlink("/sem");
	sem_unlink("/msg");
	data->semaphore = sem_open("/sem", O_CREAT, S_IRWXU, data->n_of_philo);
	//sem_wait(data->semaphore);
	//printf("ABC\n");
	data->sem_msg = sem_open("/msg", O_CREAT, S_IRWXU, 1);
	//printf("%lld\n", (long long)data->sem_msg);
}

void	p_assigment(t_data *data, int argc, char ** argv)
{
	data->n_of_philo = ft_atoi(argv[1]);
	data->philo = malloc(sizeof(t_philos) * data->n_of_philo);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->n_of_ph_m_eat = -1;
	if (argc == 6)
		data->n_of_ph_m_eat = ft_atoi(argv[5]);
	//sem(data);
}

int main(int argc,char **argv)
{
	if (argc == 5 || argc == 6)
	{
		t_data *data;

		if (!arg_check(argc, argv))
		{
			error("Arg Error! Invalid Arg");
			return (0);
		}
		data = malloc(sizeof(t_data));
		p_assigment(data, argc, argv);
		p_fork(data);
	}
	else
		error("Arg Error!");
	return (0);
}
