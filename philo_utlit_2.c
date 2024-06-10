/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utlit_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:31:52 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/10 01:02:07 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_die(t_data *philo)
{
	if (philo->start_time == 0 &&
		get_current_time()
			- philo->access->start_simutaltion >= philo->access->t_die)
	{
		philo->access->flag = philo->id;
	}
	else if (philo->start_time && get_current_time()
			- philo->start_time >= philo->access->t_die)
	{
		philo->access->flag = philo->id;
	}
}

int	should_stop(t_data *philo, int n, int n_meals)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (philo[i].count == n_meals)
			j++;
		i++;
	}
	// printf("---------+%d++-----\n", j);
	if (j == n)
		return (0);
	return (1);
}