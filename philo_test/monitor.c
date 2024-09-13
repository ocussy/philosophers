/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:24:47 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/13 16:30:39 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_eaten(t_sim *sim)
{
	pthread_mutex_lock(&sim->mutex_total_meal);
	if (sim->total_meal == sim->nb_philo)
	{
		pthread_mutex_unlock(&sim->mutex_total_meal);
		return (1);
	}
	pthread_mutex_unlock(&sim->mutex_total_meal);
	return (0);
}

int	check_death(t_sim *sim)
{
	pthread_mutex_lock(&sim->mutex_dead);
	if (sim->is_dead == true)
	{
		pthread_mutex_unlock(&sim->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&sim->mutex_dead);
	return (0);
}

void	print_death(t_sim *sim, int i)
{
	pthread_mutex_lock(&sim->mutex_print);
	pthread_mutex_lock(&sim->mutex_total_meal);
	if (sim->total_meal != (sim->nb_philo - 1) || sim->nb_philo == 1)
	{
		printf("%lld %d died\n", get_time_ms() - sim->start_time,
			sim->philo[i].id);
	}
	pthread_mutex_unlock(&sim->mutex_total_meal);
	pthread_mutex_unlock(&sim->mutex_print);
}

int	monitor_death(t_sim *sim)
{
	long long	current_time;
	int			i;

	i = 0;
	current_time = get_time_ms() - sim->start_time;
	while (i < sim->nb_philo)
	{
		pthread_mutex_lock(&sim->mutex_last_meal);
		if (current_time - sim->philo[i].last_eat >= sim->time_to_die)
		{
			pthread_mutex_lock(&sim->mutex_dead);
			sim->is_dead = true;
			pthread_mutex_unlock(&sim->mutex_dead);
			print_death(sim, i);
			pthread_mutex_unlock(&sim->mutex_last_meal);
			return (1);
		}
		pthread_mutex_unlock(&sim->mutex_last_meal);
		i++;
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_sim	*sim;

	sim = (t_sim *)arg;
	wait_philo(sim);
	while (1)
	{
		if (check_all_eaten(sim))
			break ;
		if (check_death(sim))
			break ;
		if (monitor_death(sim) == 1)
			break ;
		usleep(100);
	}
	return (NULL);
}
