/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:21:14 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/03 17:14:36 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosophers_args(t_sim *sim, t_philo *philo_arg,
		pthread_mutex_t *fork, t_info *info)
{
	int	i;

	i = 0;
	while (i < ft_atoi(info->nb_philo))
	{
		philo_arg[i].time_to_die = ft_atoi(info->time_to_die);
		philo_arg[i].time_to_sleep = ft_atoi(info->time_to_sleep);
		philo_arg[i].time_to_eat = ft_atoi(info->time_to_eat);
		philo_arg[i].nb_philo = ft_atoi(info->nb_philo);
		if (info->nb_time_eat != 0)
			philo_arg[i].nb_time_eat = ft_atoi(info->nb_time_eat);
		else
			philo_arg[i].nb_time_eat = -1;
		philo_arg[i].meals_eaten = 0;
		philo_arg[i].id = i + 1;
		philo_arg[i].left_fork = &fork[i];
		philo_arg[i].right_fork = &fork[(i + 1) % philo_arg->nb_philo];
		philo_arg[i].last_eat = 0;
		philo_arg[i].status = IS_THINKING;
		if (pthread_mutex_init(&philo_arg[i].status_mutex, NULL) != 0)
			exit(1);
		philo_arg[i].meal_mutex = &sim->meal_mutex;
		philo_arg[i].philo_meal_end = 0;
		philo_arg[i].mutex_dead = &sim->mutex_dead;
		philo_arg[i].printf_mutex = &sim->printf_mutex;
		philo_arg[i].add_meal = &sim->add_meal;
		philo_arg[i].last_meal = &sim->last_meal;
		philo_arg[i].is_dead = 0;
		i++;
	}
	// pthread_mutex_init(&philo_arg->mutex_dead, NULL);
}

void	start_simulation(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		if (pthread_create(&sim->philosophers[i], NULL, philosopher,
				&sim->philo_args[i]) != 0)
			return ;
		i++;
	}
	if (pthread_create(&sim->monitoring_thread, NULL, monitoring, sim) != 0)
		return ;
}

int	init_simulation(t_sim *sim, t_info *info)
{
	int	i;

	i = 0;
	sim->nb_philo = ft_atoi(info->nb_philo);
	while (i < sim->nb_philo)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&sim->printf_mutex, NULL);
	pthread_mutex_init(&sim->mutex_dead, NULL);
	pthread_mutex_init(&sim->meal_mutex, NULL);
	pthread_mutex_init(&sim->add_meal, NULL);
	pthread_mutex_init(&sim->last_meal, NULL);
	init_philosophers_args(sim, sim->philo_args, sim->forks, info);
	return (0);
}

void	clean_simulation(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		if (pthread_join(sim->philosophers[i], NULL) != 0)
			return ;
		i++;
	}
	if (pthread_join(sim->monitoring_thread, NULL) != 0)
		return ;
	i = 0;
	while (i < sim->nb_philo)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		pthread_mutex_destroy(&sim->philo_args[i].status_mutex);
		i++;
	}
	pthread_mutex_destroy(&sim->meal_mutex);
	pthread_mutex_destroy(&sim->mutex_dead);
	pthread_mutex_destroy(&sim->printf_mutex);
}
