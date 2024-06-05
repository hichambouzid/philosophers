
#include "philo.h"


void *eat(void *data)
{
	t_philo *philo;
	t_data *infos;

	philo = (t_philo *)data;
		// printf("the index is : %d\n", philo->index);
	infos = philo->thread_mutex;

if (safe_mutex_handle(philo->thread_mutex[philo->index].left, LOCK) || 
		safe_mutex_handle(philo->thread_mutex[philo->index].right, LOCK))
		{
			ft_free(philo, philo->n_philo);
			return (NULL);
		}
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

}

int start_eating(t_philo *data)
{
	int i;
	int j;
	void *m;
	i = 0;
	j = 0;
	// for (int i = 0; i < data->n_philo; i++)
	// 	{
	// 		if (!data->thread_mutex[i].left || !data->thread_mutex[i].right)
	// 			printf("error l3sha\n");
	// 		// printf("%p   %d  %p\n", &data->thread_mutex[i].left, i, &data->thread_mutex[i].right);
	// 		printf("%p %d\n", data->forks[i], i);
	// 	}
	while (j <= data->n_repeat)
	{
		if (data->n_repeat == 0)
		{
			while (1)
			{
				// printf("i'm here\n");
				if (i == data->n_philo)
					i = 0;
				data->index = i;
				// printf("----------> %d\n", i);
				pthread_create(&data->philo[i], NULL, eat, data);
				if (pthread_join(data->philo[i], &m))
					printf("error pthraed join \n");
				printf("im here\n");
				if (check_if_die(data))
				{
					printf("%ld %d die\n", (get_current_time() - data->start_simutaltion) / 1000,
						data->index + 1);
					ft_free(data, data->n_philo - 1);
					return (0);
				}
				i++;
			}
			return (0);
		}
		else
		{
			printf("==================================\n");
			if (i == data->n_repeat)
			{
					j++;
					i = 0;
			}
			data->index = i;
			pthread_create(&data->philo[i], NULL, eat, data);
			if (pthread_join(data->philo[i], &m))
				printf("error in pthaed_join\n");
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
		printf("-------------------------------> %d\n", data->n_repeat);
		// for (int i = 0; i < data->n_philo; i++)
		// {
		// 	if (!data->thread_mutex[i].left || !data->thread_mutex[i].right)
		// 		printf("error l3sha\n");
		// 	printf("%p   %d  %p\n", &data->thread_mutex[i].left, i, &data->thread_mutex[i].right);
		// }
		start_eating(data);
	}
	else
		return (printf("number of argument is invalide"));

	// system("leaks philo");
}
