/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:53:01 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/11 00:06:19 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(long d)
{
	usleep(d);
}

void	ft_print(void *data, int i, char *str)
{
	t_data	*d;
printf("started\n");
	d = (t_data *)data;
	if (d->access->flag != -1)
		return ;
	safe_mutex_handle(d->access->print, LOCK);
	if ((i == 0 || i == 2 || i == 3) && d->access->flag == -1)
		printf("%ld %d %s\n",
				(get_current_time() - d->access->start_simutaltion) / 1000,
				d->id,
				str);
	else if (i == 1 && d->access->flag == -1)
	{
		d->count++;
		printf("%ld %d %s\n", (get_current_time()
					- d->access->start_simutaltion) / 1000, d->id, str);
	}
	
	safe_mutex_handle(d->access->print, UNLOCK);
printf("end\n");
}

void	*eat(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	// safe_mutex_handle(d->left, LOCK);
	// safe_mutex_handle(d->right, LOCK);
	while (1 && d->access->flag == -1)
	{
		
		safe_mutex_handle(d->right, LOCK);
		ft_print(d, 0, "has taken the first fork");
		safe_mutex_handle(d->left, LOCK);
		ft_print(d, 0, "has taken the second fork");
		ft_check_die(d);
		ft_print(d, 1, "is eating");
		d->start_time = get_current_time();
		printf("starte");
		usleep(d->access->t_eat);
		printf("right\n");
		safe_mutex_handle(d->left, UNLOCK);
		safe_mutex_handle(d->right, UNLOCK);
		ft_print(d, 2, "is sleeping");
		usleep(d->access->t_sleep);
		ft_print(d, 3, "is thinking");
		if (d->access->n_repeat && d->count == d->access->n_repeat)
			return (NULL);
	}
	return (NULL);
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

void	start_eating(t_philo *data, int ac)
{
	int		i;
	void	*m;

	(void)ac;
	// int j;
	i = 0;
	if (data->n_philo > 1)
	{
		data->start_simutaltion = get_current_time();
		odd(data);
		usleep(200);
		even(data);
		while (1)
		{
			if (data->flag != -1)
			{
				safe_mutex_handle(data->print, LOCK);
				printf("%ld %d died\n", (get_current_time()
							- data->start_simutaltion) / 1000, data->flag);
					safe_mutex_handle(data->print, UNLOCK);
				// ft_free(data, data->n_philo - 1);
				break ;
			}
			if (ac == 6 && !should_stop(data->thread_mutex, data->n_philo,
					data->n_repeat))
				{
					break ;
				}
			// printf("-\n");
		}
	}
	while (i < data->n_philo)
		pthread_join(data->philo[i++], &m);
	ft_free(data, data->n_philo - 1);
}

int	main(int ac, char **av)
{
	t_philo *data;

	if (ac == 1)
		return (0);
	if (ac < 5 || ac > 6)
		return (printf("invalide number of argumment\n"));
	data = fill_struct(ac, av);
	if (!data || init_data(data))
		return (printf("command not valide \n"));
	start_eating(data, ac);
}