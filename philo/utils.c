#include "philo.h"

long	get_time()
{
	struct timeval	tv;
	long			time;
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return(time);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	neg = 1;
	res = 0;
	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}
