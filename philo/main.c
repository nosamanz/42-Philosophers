#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void	*worker_thread()
// {
// 	printf("This is worker_thread\n");
// 	return (NULL);
// }

// int	main(void)
// {
// 	pthread_t my_thread;
// 	int ret;

// 	printf("In main.\n");
// 	ret = pthread_create(&my_thread, NULL, &worker_thread, NULL);
// 	if (ret != 0)
// 		printf("%d\n", ret);
// 	pthread_join(my_thread, NULL);
// 	return (0);
// }

void *worker_thread(void *id)
{
	printf("THREAD #%ld\n", (long)id);
	return(NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	threads[10];
	int check;
	long id = 1;

	for (id = 1; id <= 10; id++);
	{
		check = pthread_create(&threads[id], NULL, worker_thread, (void *)id);
		if (check != 0)
		{
			printf("Error!");
			return (0);
		}
	}
	id = 1;
    for(id = 1; id <= 10; id++) {
		pthread_join(threads[id], NULL);
  	}
}
