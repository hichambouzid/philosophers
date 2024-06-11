#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_printf(void *args)
{
	int	*num;

	num = (int *)args;
	for (int i = 0; i < *num; i++)
		printf("the thread %d is runnig\n", *num);
	return (NULL);
}

// int	main(void)
// {
// 	pthread_t thread1, thread2;
// 	int num1 = 100000, num2 = 2000000;

// 	pthread_create(&thread1, NULL, ft_printf, &num1);
// 	pthread_create(&thread2, NULL, ft_printf, &num2);

// 	pthread_join(thread1, NULL);
// 	pthread_join(thread2, NULL);

// 	printf("the main thread is finished\n");
// }