/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utlit_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:31:52 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/11 16:16:26 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_die(t_data *philo)
{
	int	i;

	i = 0;
	while (i < philo->access->n_philo)
	{
		if (philo[i].start_time == 0 && get_current_time()
			- philo[i].access->start_simutaltion >= philo[i].access->t_die
			&& philo[i].access->t_die > 0)
			philo[i].access->flag = philo[i].id;
		else if (philo[i].start_time && get_current_time()
			- philo[i].start_time >= philo[i].access->t_die)
			philo[i].access->flag = philo[i].id;
		i++;
	}
}

int	should_stop(t_data *philo, int n, int n_meals)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (philo[i].count == n_meals)
			j++;
		i++;
	}
	if (j == n)
		return (0);
	return (1);
}

void	even(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (i % 2 == 0)
		{
			pthread_create(&data->philo[i], NULL, eat, &data->thread_mutex[i]);
			usleep(100);
		}
		i++;
	}
	return ;
}

void	odd(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (i % 2 != 0)
			pthread_create(&data->philo[i], NULL, eat, &data->thread_mutex[i]);
		i++;
	}
	return ;
}
