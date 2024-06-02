/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:26:13 by hibouzid          #+#    #+#             */
/*   Updated: 2024/06/02 21:17:54 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>

typedef struct philo
{
	int n_philo;
	long start_simutaltion;
	int t_die;
	int t_eat;
	int t_sleep;
	int n_repeat;
	pthread_mutex_t *forks;
	pthread_t *philo;
} t_philo;


typedef enum UPCODE{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
	
} t_upcode;
// typedef struct s_data
// {
// 	int id;
// 	pthread_t *thead;
// 	pthread_mutex_t *left;
// 	pthread_mutex_t right;
// }t_data;

typedef struct elemet{
	int i;
	int num;
	int sign;
} t_el;

# define INT_MIN -2147483648
# define INT_MAX 2147483647

int	ft_atoi(char *str);
int ft_strlen(char *str);
t_philo *fill_struct(int ac, char **av);
void ft_putstr(char *str, int fd);

#endif