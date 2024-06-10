#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL))
		return (0);
	// sleep(10);
	printf("time in second since 1970 %ld\n", time.tv_sec * 1000);
	printf("time in mecro mili %d\n", time.tv_usec / 1000);
	int i = 0;
	long total = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	// while (1)
	// {
	// 	if (i == 10000000)
	// 		break ;
	// 	i++;
	// }
	usleep(200000);
	if (gettimeofday(&time, NULL))
		return (0);
	long total1 = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	printf("------>time to sleep %ld\n", total1 - total);
}