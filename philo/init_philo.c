/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:21:14 by ocussy            #+#    #+#             */
/*   Updated: 2024/08/30 17:28:35 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosophers_args(t_philo *philo_arg, pthread_mutex_t *fork,
		t_info *info)
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
		if (pthread_mutex_init(&philo_arg[i].meal_mutex, NULL) != 0)
			exit(1);
		i++;
	}
	philo_arg->philo_meal_end = 0;
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
	i = 0;
	while (i < sim->nb_philo)
	{
		if (pthread_join(sim->philosophers[i], NULL) != 0)
			return ;
		i++;
	}
	if (pthread_join(sim->monitoring_thread, NULL) != 0)
		return ;
}

void	init_simulation(t_sim *sim, t_info *info)
{
	int	i;

	i = 0;
	sim->nb_philo = ft_atoi(info->nb_philo);
	while (i < sim->nb_philo)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	init_philosophers_args(sim->philo_args, sim->forks, info);
}

void	clean_simulation(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philo)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		pthread_mutex_destroy(&sim->philo_args[i].status_mutex);
		pthread_mutex_destroy(&sim->philo_args[i].meal_mutex);
		i++;
	}
	// free(sim->monitoring_thread);
	// free(sim->philosophers);
}
