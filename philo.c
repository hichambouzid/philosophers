
#include "philo.h"







int main(int ac, char **av)
{
	t_philo *data;

	if (ac == 1)
		return (0);
	if (ac == 5 || ac == 6)
	{
		data = fill_struct(ac, av);
		// for (int i -)
		if (!data)
			return (printf("command not valide\n"));
		 printf("---> %d\n", data->n_philo);
		 printf("---> %d\n", data->t_die);
		 printf("---> %d\n", data->t_eat);
		 printf("---> %d\n", data->t_sleep);
		 printf("---> %d\n", data->n_repeat);

	}
	else
		return (printf("number of argument is invalide"));
}
















// pthread_mutex_t forks;
void *ft_func(void *i)
{
	int *nbr;

	nbr = (int *)i;
	(*nbr)++;
	return NULL;
}

// int main(int ac, char **av)
// {
// 	pthread_mutex_t *mutex;
// 	t_philo *data;
// 	// void *message;
// 	// t_opcode code;
// 	if (ac == 1)
// 		return (0);
// 	(void)mutex;
// 	data = fill_struct(ac, av);
// 	if (!data)
// 		return (printf("Error in parsing of args\n"));
// 	data->forks = malloc(sizeof(pthread_t *) * (data->n_philo));
// 	data->philo = malloc(sizeof(pthread_mutex_t *) * (data->n_philo));
// 	if (!data->forks || !data->philo)
// 		return (0);
// 	for (int i = 0; i < data->n_philo; i++)
// 	{
// 		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
// 			return (printf("error in pthread mutex \n"));
// 	}
// 	for (int i = 0; i < data->n_philo; )
// 	{
// 		pthread_mutex_lock(&data->forks[i]);
// 		printf("ms %d is taken a fork\n", i);
// 		pthread_mutex_lock(&data->forks[i + 1 % data->n_philo]);
// 		printf("ms %d is taken a fork\n", i);
// 		pthread_create(&data->philo[i], NULL, ft_func, &i);
// 		printf("ms %d is eating\n", i);
// 		usleep(data->t_eat);
// 		pthread_mutex_unlock(&data->forks[i]);
// 		pthread_mutex_unlock(&data->forks[i + 1 % data->n_philo]);
// 		printf("ms %d is sleeping\n" , data->n_philo);
// 		printf("ms %d is sleeping\n" , data->n_philo);
// 		usleep(data->t_sleep);
// 		// printf("error in usleep\n");

// 	}
// 	for (int i = 0; i < data->n_philo; i++)
// 	{
// 		pthread_join(data->philo[i], NULL);
// 	}
// 	// for (int i -)
// 	// printf("---> %d\n", data->n_philo);
// 	// printf("---> %d\n", data->t_die);
// 	// printf("---> %d\n", data->t_eat);
// 	// printf("---> %d\n", data->t_sleep);
// 	// printf("---> %d\n", data->n_repeat);

// }