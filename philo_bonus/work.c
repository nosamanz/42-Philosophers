#include "philo_bonus.h"

void	eating(t_philos *philo)
{
	//msg(get_time(), "eating", philo->id, data);
	sem_wait(philo->data->semaphore);
	sem_wait(philo->data->semaphore);
	printf("asdf\n");
	//printf("Philo[%d] is eating\n", philo->id);
	//printf("taking fork RIGHT\n");
	//msg(get_time(), "taking fork RIGHT", philo->id, data);
	sem_post(philo->data->semaphore);
	//msg(get_time(), "taking fork LEFT", philo->id, data);
	sem_post(philo->data->semaphore);
}

void	work(t_philos *philo, int i)
{
	philo->id = i;
	t_data *data;


	data = malloc(sizeof(t_data));
	sem(data);
	data = philo->data;
	if (philo->id % 2 == 0)
		sleep(3);
	//printf("i am child process ID : %d\n", philo->id);
	//eating(philo);
	//msg(get_time(), "eating", philo->id, data);
	sem_wait(data->semaphore);
	printf("asdf\n");
	//sem_wait(data->semaphore);
	//printf("Philo[%d] is eating\n", philo->id);
	//printf("taking fork RIGHT\n");
	//msg(get_time(), "taking fork RIGHT", philo->id, data);
	sem_post(philo->data->semaphore);
	//msg(get_time(), "taking fork LEFT", philo->id, data);
	sem_post(philo->data->semaphore);
	//printf("Philo[%d] is sleeping\n", philo->id);
	//printf("Philo[%d] is thinking\n", philo->id);
}
