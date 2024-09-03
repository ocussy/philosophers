/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:55:55 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/03 14:38:58 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	eat_even(long long start_time, t_philo *args, int philo_id)
// {
// 	pthread_mutex_lock(args->right_fork);
// 	pthread_mutex_lock(&args->mutex_dead);
// 	if (args->is_dead == 0)
// 		printf("%lld %d has taken a fork\n", get_time_ms() - start_time,
// 			philo_id);
// 	else
// 	{
// 		pthread_mutex_unlock(args->right_fork);
// 		pthread_mutex_unlock(&args->mutex_dead);
// 		return ;
// 	}
// 	if (args->nb_philo == 1)
// 	{
// 		pthread_mutex_unlock(args->right_fork);
// 		usleep(args->time_to_die * 1000);
// 		args->is_dead = 1;
// 		pthread_mutex_unlock(&args->mutex_dead);
// 		return ;
// 	}
// 	pthread_mutex_lock(args->left_fork);
// 	pthread_mutex_lock(&args->status_mutex);
// 	args->status = IS_EATING;
// 	pthread_mutex_unlock(&args->status_mutex);
// 	if (args->is_dead == 0)
// 	{
// 		printf("%lld %d has taken a fork\n", get_time_ms() - start_time,
// 			philo_id);
// 		printf("%lld %d is eating\n", get_time_ms() - start_time, philo_id);
// 	}
// 	else
// 	{
// 		pthread_mutex_unlock(args->right_fork);
// 		pthread_mutex_unlock(args->left_fork);
// 		pthread_mutex_unlock(&args->mutex_dead);
// 		return ;
// 	}
// 	usleep(args->time_to_eat * 1000);
// 	args->meals_eaten++;
// 	args->last_eat = get_time_ms() - start_time;
// 	pthread_mutex_unlock(&args->mutex_dead);
// 	pthread_mutex_unlock(args->left_fork);
// 	pthread_mutex_unlock(args->right_fork);
// }

// void	eat_odd(long long start_time, t_philo *args, int philo_id)
// {
// 	pthread_mutex_lock(args->left_fork);
// 	pthread_mutex_lock(&args->mutex_dead);
// 	if (args->is_dead == 0)
// 		printf("%lld %d has taken a fork\n", get_time_ms() - start_time,
// 			philo_id);
// 	else
// 	{
// 		pthread_mutex_unlock(args->left_fork);
// 		pthread_mutex_unlock(&args->mutex_dead);
// 		return ;
// 	}
// 	if (args->nb_philo == 1)
// 	{
// 		pthread_mutex_unlock(args->left_fork);
// 		usleep(args->time_to_die * 1000);
// 		args->is_dead = 1;
// 		pthread_mutex_unlock(&args->mutex_dead);
// 		return ;
// 	}
// 	pthread_mutex_lock(args->right_fork);
// 	pthread_mutex_lock(&args->status_mutex);
// 	args->status = IS_EATING;
// 	pthread_mutex_unlock(&args->status_mutex);
// 	if (args->is_dead == 0)
// 	{
// 		printf("%lld %d has taken a fork\n", get_time_ms() - start_time,
// 			philo_id);
// 		printf("%lld %d is eating\n", get_time_ms() - start_time, philo_id);
// 	}
// 	else
// 	{
// 		pthread_mutex_unlock(args->left_fork);
// 		pthread_mutex_unlock(args->right_fork);
// 		pthread_mutex_unlock(&args->mutex_dead);
// 		return ;
// 	}
// 	usleep(args->time_to_eat * 1000);
// 	args->meals_eaten++;
// 	args->last_eat = get_time_ms() - start_time;
// 	pthread_mutex_unlock(&args->mutex_dead);
// 	pthread_mutex_unlock(args->right_fork);
// 	pthread_mutex_unlock(args->left_fork);
// }
