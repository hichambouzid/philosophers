/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:20:15 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/07 01:22:24 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int	safe_mutex_handle(pthread_mutex_t *fork, t_upcode UPCODE)
{
	if (UPCODE == INIT)
		return (pthread_mutex_init(fork, NULL));
	else if (UPCODE == LOCK)
		return (pthread_mutex_lock(fork));
	else if (UPCODE == UNLOCK)
		return (pthread_mutex_unlock(fork));
	else if (UPCODE == DESTROY)
		return (pthread_mutex_destroy(fork));
	else
		ft_putstr("error was happen in mutex handler function\n", 2);
	return (-1);
}

static void	assigne_data(t_philo *data)
{
	int		i;
	t_data	*da;

	i = 0;
	da = data->thread_mutex;
	data->flag = -1;
	while (i < data->n_philo)
	{
		if (data->n_philo % 2 == 0)
		{
			da[i].left = &data->forks[(i + 1) % data->n_philo];
			da[i].right = &data->forks[i];
		}
		if (data->n_philo % 2)
		{
			da[i].left = &data->forks[(i + 1)];
			da[i].right = &data->forks[i];
		}
		da[i].end_time = 0;
		da[i].start_time = 0;
		da[i].count = 0;
		// printf("------------>%d and %d\n", (i + 1) % data->n_philo, i);
		// if (!da[i].right || !da[i].left)
		// 	printf("l3sha\n");
		da[i].access = data;
		da[i].thread = &data->philo[i];
		i++;
	}
	data->thread_mutex = da;
}

int	init_data(t_philo *data)
{
	int	i;

	i = 0;
	if (!data)
		return (-1);
	data->philo = malloc(sizeof(pthread_t) * data->n_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->n_philo));
	data->thread_mutex = malloc(sizeof(t_data) * (data->n_philo));
	data->print = malloc(sizeof(t_data));
	while (i < data->n_philo)
	{
		if (safe_mutex_handle(&data->forks[i], INIT) == -1)
		{
			// printf("im hslvnslere\n");
			ft_free(data, i);
			return (-1);
		}
		data->thread_mutex[i].id = i + 1;
		// data->thread_mutex[i].thread = data->philo[i];
		i++;
	}
	assigne_data(data);
	return (0);
}

long	get_current_time(void)
{
	struct timeval time;
	long nbr;

	if (gettimeofday(&time, NULL))
	{
		ft_putstr("error was happen ind gettimeofday\n", 2);
		return (-1);
	}
	nbr = time.tv_sec * 1000000;
	nbr += time.tv_usec;
	return (nbr);
}