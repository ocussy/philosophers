/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:43:53 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/13 16:47:48 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	eat_even(t_sim *sim, t_philo *philo)
// {
// 	pthread_mutex_lock(philo->right_fork);
// 	if (print_action(sim, philo, "has taken a fork") == 1)
// 	{
// 		pthread_mutex_unlock(philo->right_fork);
// 		return (1);
// 	}
// 	pthread_mutex_lock(philo->left_fork);
// 	if (print_action(sim, philo, "has taken a fork") == 1)
// 	{
// 		pthread_mutex_unlock(philo->left_fork);
// 		pthread_mutex_unlock(philo->right_fork);
// 		return (1);
// 	}
// 	pthread_mutex_lock(&sim->mutex_last_meal);
// 	philo->last_eat = get_time_ms() - sim->start_time;
// 	pthread_mutex_unlock(&sim->mutex_last_meal);
// 	if (print_action(sim, philo, "is eating") == 1)
// 	{
// 		pthread_mutex_unlock(philo->left_fork);
// 		pthread_mutex_unlock(philo->right_fork);
// 		return (1);
// 	}
// 	if (usleep_check(sim, sim->time_to_eat) == 1)
// 	{
// 		pthread_mutex_unlock(philo->left_fork);
// 		pthread_mutex_unlock(philo->right_fork);
// 		return (1);
// 	}
// 	pthread_mutex_lock(&sim->mutex_add_meal);
// 	philo->nb_meal++;
// 	pthread_mutex_unlock(&sim->mutex_add_meal);
// 	pthread_mutex_unlock(philo->left_fork);
// 	pthread_mutex_unlock(philo->right_fork);
// 	return (0);
// }

// int	eat_odd(t_sim *sim, t_philo *philo)
// {
// 	pthread_mutex_lock(philo->left_fork);
// 	if (print_action(sim, philo, "has taken a fork") == 1)
// 	{
// 		pthread_mutex_unlock(philo->left_fork);
// 		return (1);
// 	}
// 	if (sim->nb_philo == 1)
// 	{
// 		usleep(sim->time_to_die * 1000);
// 		pthread_mutex_unlock(philo->left_fork);
// 		return (1);
// 	}
// 	pthread_mutex_lock(philo->right_fork);
// 	if (print_action(sim, philo, "has taken a fork") == 1)
// 	{
// 		pthread_mutex_unlock(philo->right_fork);
// 		pthread_mutex_unlock(philo->left_fork);
// 		return (1);
// 	}
// 	pthread_mutex_lock(&sim->mutex_last_meal);
// 	philo->last_eat = get_time_ms() - sim->start_time;
// 	pthread_mutex_unlock(&sim->mutex_last_meal);
// 	if (print_action(sim, philo, "is eating") == 1)
// 	{
// 		pthread_mutex_unlock(philo->right_fork);
// 		pthread_mutex_unlock(philo->left_fork);
// 		return (1);
// 	}
// 	if (usleep_check(sim, sim->time_to_eat) == 1)
// 	{
// 		pthread_mutex_unlock(philo->right_fork);
// 		pthread_mutex_unlock(philo->left_fork);
// 		return (1);
// 	}
// 	pthread_mutex_lock(&sim->mutex_add_meal);
// 	philo->nb_meal++;
// 	pthread_mutex_unlock(&sim->mutex_add_meal);
// 	pthread_mutex_unlock(philo->right_fork);
// 	pthread_mutex_unlock(philo->left_fork);
// 	return (0);
// }

int	take_forks(t_sim *sim, t_philo *philo, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(first_fork);
	if (print_action(sim, philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(first_fork);
		return (1);
	}
	pthread_mutex_lock(second_fork);
	if (print_action(sim, philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(second_fork);
		pthread_mutex_unlock(first_fork);
		return (1);
	}
	return (0);
}

int	eat_action(t_sim *sim, t_philo *philo, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(&sim->mutex_last_meal);
	philo->last_eat = get_time_ms() - sim->start_time;
	pthread_mutex_unlock(&sim->mutex_last_meal);
	if (print_action(sim, philo, "is eating") == 1)
	{
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		return (1);
	}
	if (usleep_check(sim, sim->time_to_eat) == 1)
	{
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		return (1);
	}
	pthread_mutex_lock(&sim->mutex_add_meal);
	philo->nb_meal++;
	pthread_mutex_unlock(&sim->mutex_add_meal);
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
	return (0);
}

int	eat_even(t_sim *sim, t_philo *philo)
{
	if (take_forks(sim, philo, philo->right_fork, philo->left_fork) == 1)
		return (1);
	if (eat_action(sim, philo, philo->right_fork, philo->left_fork) == 1)
		return (1);
	return (0);
}

int	eat_odd(t_sim *sim, t_philo *philo)
{
	if (take_forks(sim, philo, philo->left_fork, philo->right_fork) == 1)
		return (1);
	if (eat_action(sim, philo, philo->left_fork, philo->right_fork) == 1)
		return (1);
	return (0);
}
