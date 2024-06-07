/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:53:01 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/07 16:54:06 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_sleep(long d)
{
	usleep(d);
}

void *eat(void *data)
{
	t_data *d;
	
	d = (t_data *)data;
	while (1)
	{
		if (d && d->access->flag != -1)
			return (NULL);
			if (!d->start_time)
				d->start_time = get_current_time();
		if (d->start_time && get_current_time() - d->start_time >= d->access->t_die)
		{
			printf("-----------------> last time eat %ld \n",( get_current_time() - d->start_time) / 1000);
			printf("-----------------> time to die %d\n", d->access->t_die / 1000);
			d->access->flag = d->id ;
			
		}
		if (safe_mutex_handle(d->left, LOCK) ||
			safe_mutex_handle(d->right, LOCK))
			break ;
		printf("%ld %d has taken a fork\n", (get_current_time() - d->access->start_simutaltion) / 1000, d->id);
		printf("%ld %d has taken a fork\n", (get_current_time() - d->access->start_simutaltion) / 1000, d->id);
		d->start_time = get_current_time();
		printf("%ld %d is eating\n", (d->start_time - d->access->start_simutaltion) / 1000, d->id);
		usleep(d->access->t_eat);
		if (safe_mutex_handle(d->left, UNLOCK) || safe_mutex_handle(d->right, UNLOCK))
			break ;
		printf("%ld %d is sleeping\n", (get_current_time() - d->access->start_simutaltion) / 1000, d->id);
		ft_sleep(d->access->t_sleep);
	}
	return (NULL);
}

void even(t_philo *data)
{
	int i;

	i = 0;
	while (i < data->n_philo)
	{
		if (i % 2 == 0)
			pthread_create(&data->philo[i], NULL, eat, &data->thread_mutex[i]);
		i++;
	}
	return ;
}

void odd(t_philo *data)
{
	int i;

	i = 0;
	while (i < data->n_philo)
	{
		if (i % 2 != 0)
			pthread_create(&data->philo[i], NULL, eat, &data->thread_mutex[i]);
		i++;
	}
}

void start_eating(t_philo *data)
{
	int i;
	// int j;
	void *m;

	i = 0;
	if (data->n_philo > 1)
	{
		data->start_simutaltion = get_current_time();
		even(data);
		// usleep(200);
		odd(data);
		while (1)
		{
			if (data->flag != -1)
			{
				printf("%ld %d died\n", (get_current_time() - data->start_simutaltion) / 1000, data->flag);
				ft_free(data, data->n_philo - 1);
				return ;
			}
		}
	}
	while (i < data->n_philo)
		pthread_join(data->philo[i], &m);
}

int main(int ac, char **av)
{
	t_philo *data;

	if (ac == 1)
		return (0);
	if (ac <  5 || ac > 6)
		return (printf("invalide number of argumment\n"));
	data = fill_struct(ac, av);
	if (!data || init_data(data))
		return (printf("command not valide \n"));
	// data->start_simutaltion  = get_current_time();
	start_eating(data);
	// printf("----> %d\n", data->flag);
}