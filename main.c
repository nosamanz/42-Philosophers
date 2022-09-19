#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t lock;

void *worker_thread(void *id)
{
	static int work;
	int i = 0;

	pthread_mutex_lock(&lock);
	work += 1;
	printf("work %d has started\n", work);
	while (i <= 15)
		i++;
	printf("work %d has finished\n", work);
	pthread_mutex_unlock(&lock);
	return(NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	threads[10];
	int create;
	long id = 0;;

	// if (pthread_mutex_init(&lock, NULL) != 0)
	// {
	// 	printf("mutex init failed\n");
	// 	return 0;
	// }
	while (id <= 10)
	{
		create = pthread_create(&threads[id], NULL, worker_thread, (void *)id);
		if (create != 0)
		{
			printf("Error!");
			return (0);
		}
		id++;
	}
	id = 1;
	while (id <= 10)
	{
		pthread_join(threads[id], NULL);
		id++;
	}
}

// #include <sys/time.h>
// #include <stdio.h>

// int main()
// {
//   struct timeval current_time;
//   gettimeofday(&current_time, NULL);
//   int a = current_time.tv_sec;
//   int b = current_time.tv_usec;
//   // printf("seconds : %ld\nmicro seconds : %d",
//   //   current_time.tv_sec, current_time.tv_usec);
//   sleep(3);
//   gettimeofday(&current_time, NULL);
//   printf("\nseconds : %ld\nmicro seconds : %d",
//     current_time.tv_sec - a, current_time.tv_usec - b);
//   return 0;
// }
