/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:49:21 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/13 13:35:04 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosophers_args(t_sim *sim, t_philo *philo,
		pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[(i + 1) % sim->nb_philo];
		philo[i].last_eat = 0;
		philo[i].nb_meal = 0;
		philo[i].sim = sim;
		i++;
	}
}

int	init_mutexes(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&sim->mutex_print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->mutex_dead, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->mutex_meal, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->mutex_add_meal, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->mutex_last_meal, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->mutex_start, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&sim->mutex_total_meal, NULL) != 0)
		return (1);
	return (0);
}

int	init_simulation(t_sim *sim, t_info *info)
{
	sim->nb_philo = ft_atoi(info->nb_philo);
	sim->time_to_die = ft_atoi(info->time_to_die);
	sim->time_to_eat = ft_atoi(info->time_to_eat);
	sim->time_to_sleep = ft_atoi(info->time_to_sleep);
	if (info->nb_time_eat != NULL)
		sim->nb_time_eat = ft_atoi(info->nb_time_eat);
	else
		sim->nb_time_eat = -1;
	sim->is_dead = false;
	sim->total_meal = 0;
	if (init_mutexes(sim) == 1)
		return (1);
	init_philosophers_args(sim, sim->philo, sim->forks);
	return (0);
}

void	start_simulation(t_sim *sim)
{
	int	i;

	i = 0;
	sim->start_time = 0;
	sim->ready = 0;
	while (i < sim->nb_philo)
	{
		if (pthread_create(&sim->philosophers[i], NULL, philosopher,
				&sim->philo[i]) != 0)
			return ;
		i++;
	}
	if (pthread_create(&sim->monitoring_thread, NULL, monitoring, sim) != 0)
		return ;
}

void	clean_simulation(t_sim *sim)
{
	int	i;

	i = 0;
	if (pthread_join(sim->monitoring_thread, NULL) != 0)
		return ;
	while (i < sim->nb_philo)
	{
		if (pthread_join(sim->philosophers[i], NULL) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < sim->nb_philo)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->mutex_print);
	pthread_mutex_destroy(&sim->mutex_dead);
	pthread_mutex_destroy(&sim->mutex_meal);
	pthread_mutex_destroy(&sim->mutex_add_meal);
	pthread_mutex_destroy(&sim->mutex_last_meal);
}
