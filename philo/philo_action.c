/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:55:55 by ocussy            #+#    #+#             */
/*   Updated: 2024/08/28 18:00:30 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_even(long long start_time, t_philo *args, int philo_id)
{
	pthread_mutex_lock(args->right_fork);
	printf("%lld %d has taken a fork\n", get_time_ms() - start_time, philo_id);
	pthread_mutex_lock(args->left_fork);
	args->status = IS_EATING;
	printf("%lld %d has taken a fork\n", get_time_ms() - start_time, philo_id);
	printf("%lld %d is eating\n", get_time_ms() - start_time, philo_id);
	usleep(args->time_to_eat * 1000);
	args->last_eat = get_time_ms() - start_time;
	pthread_mutex_unlock(args->left_fork);
	pthread_mutex_unlock(args->right_fork);
}

void	eat_odd(long long start_time, t_philo *args, int philo_id)
{
	pthread_mutex_lock(args->left_fork);
	printf("%lld %d has taken a fork\n", get_time_ms() - start_time, philo_id);
	pthread_mutex_lock(args->right_fork);
	args->status = IS_EATING;
	printf("%lld %d has taken a fork\n", get_time_ms() - start_time, philo_id);
	printf("%lld %d is eating\n", get_time_ms() - start_time, philo_id);
	usleep(args->time_to_eat * 1000);
	args->last_eat = get_time_ms() - start_time;
	pthread_mutex_unlock(args->right_fork);
	pthread_mutex_unlock(args->left_fork);
}
