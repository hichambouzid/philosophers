/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:26:13 by hibouzid          #+#    #+#             */
/*   Updated: 2024/05/24 16:16:53 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct philo
{
	int n_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int n_repeat;
} t_data;

typedef struct elemet{
	int i;
	int num;
	int sign;
} t_el;

# define INT_MIN -2147483648
# define INT_MAX 2147483647

int	ft_atoi(char *str);
int ft_strlen(char *str);
t_data *fill_struct(int ac, char **av);

#endif