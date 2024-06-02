#include "philo.h"
#include<stdio.h>
#include<sys/time.h>

int main()
{
	struct timeval time;

	if (gettimeofday(&time, NULL))
		return 0;
		// sleep(10);
	printf("time in second since 1970 %ld\n", time.tv_sec /** 60 / 60 / 24 / 365*/);
	printf("time in mecro second %d\n", time.tv_usec / 1000);
	int i = 0;
	// while (1)
	// {
	// 	if (i == 10000000)
	// 		break ;
	// 	i++;
	// }
	usleep(19000000);
	if (gettimeofday(&time, NULL))
	return (0);
	printf("------>time in mecro second %d\n", time.tv_usec );
}