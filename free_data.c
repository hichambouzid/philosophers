/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:33:11 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/06 12:41:16 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_free(t_philo *data, int index)
{
	int i;

	i = index;
	if (data)
	{
		while (i >= 0)
		{
			safe_mutex_handle(&data->forks[i], DESTROY);
			i--;
		}
		// printf("=====================================\n");
		free(data->philo);
		free(data->forks);
		free(data->thread_mutex);
		free(data);
		return (0);
	}
	return (0);
}