/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:33:11 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/10 18:12:55 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_free(t_philo *data, int index)
{
	int i;

	i = index;
	if (data)
	{
		while (i >= 0)
		{
			// safe_mutex_handle(&data->forks[i], UNLOCK);
			safe_mutex_handle(&data->forks[i], DESTROY);
			i--;
		}
		safe_mutex_handle(data->print, DESTROY);
		// printf("=====================================\n");
		free(data->philo);
		free(data->forks);
		free(data->print);
		free(data->thread_mutex);
		free(data);
		return (0);
	}
	return (0);
}