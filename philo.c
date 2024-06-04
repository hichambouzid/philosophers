
#include "philo.h"


void *eat(void *data)
{
	t_philo *philo;
	t_data *infos;

	philo = (t_philo *)data;
	infos = philo->thread_mutex;
	if (!philo->thread_mutex[philo->index].right)
		{
			printf("errooooor\n");
			return (0);
		}
	if (safe_mutex_handle(philo->thread_mutex[philo->index].left, LOCK) || 
		safe_mutex_handle(philo->thread_mutex[philo->index].right, LOCK))
		{
			ft_free(philo, philo->n_philo);
			return (NULL);
		}
	printf("=========\n");
	infos[philo->index].start_time = get_current_time();
	printf("%ld %d has taken a fork\n", (infos[philo->index].start_time - philo->start_simutaltion) / 1000, philo->index + 1);
	printf("%ld %d has taken a fork\n", (infos[philo->index].start_time - philo->start_simutaltion) / 1000, philo->index + 1);
	printf("%ld %d is eating\n", (get_current_time() - philo->start_simutaltion) / 1000, philo->index + 1);
	usleep(philo->t_eat);
	printf("%ld %d is sleeping\n", (get_current_time() - philo->start_simutaltion) / 1000, philo->index + 1);
	usleep(philo->t_sleep);
	infos[philo->index].end_time = get_current_time();
	safe_mutex_handle(philo->thread_mutex[philo->index].left, UNLOCK); 
	safe_mutex_handle(philo->thread_mutex[philo->index].right, UNLOCK);
	return (NULL);
}



static int check_if_die(t_philo *data)
{
	if (data->thread_mutex[data->index].end_time - data->thread_mutex[data->index].start_time > data->t_die)
		return (1);
	return (0);
	// if (((end / 1000) - (start / 1000)) > time_die / 1000)
	// 	return (1);
	// return (0);
}

int start_eating(t_philo *data)
{
	int i;
	int j;
	void *m;
	i = 0;
	j = 0;
	while (j <= data->n_repeat)
	{
		if (data->n_repeat == 0)
		{
			while (1)
			{
				if (i == data->n_philo)
					i = 0;
				data->index = i;
				pthread_create(&data->philo[i], NULL, eat, &data);
				// printf("=========\n");
				pthread_join(data->thread_mutex[i].thread[i], &m);
				if (check_if_die(data))
				{
					printf("%ld %d die\n", (get_current_time() - data->start_simutaltion) / 1000,
						data->index + 1);
					ft_free(data, data->n_philo);
				}
				i++;
			}
			return (0);
		}
		else
		{
			if (i == data->n_repeat)
			{
					j++;
					i = 0;
			}
			data->index = i;
			pthread_create(data->thread_mutex[i].thread, NULL, eat, &data);
			if (check_if_die(data))
			{
				printf("%ld %d die\n", (get_current_time() - data->start_simutaltion) / 1000,
					data->index + 1);
				ft_free(data, data->n_philo);
			}
			i++;
		}

	}
	return (0);
}

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
		if (init_data(data))
			return (printf("error\n"));
		data->start_simutaltion = get_current_time();
		start_eating(data);
	}
	else
		return (printf("number of argument is invalide"));

	// system("leaks philo");
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