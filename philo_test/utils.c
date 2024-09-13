/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:31:31 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/13 16:32:36 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	wait_philo(t_sim *sim)
{
	pthread_mutex_lock(&sim->mutex_start);
	sim->ready++;
	if (sim->ready == sim->nb_philo + 1)
		sim->start_time = get_time_ms();
	pthread_mutex_unlock(&sim->mutex_start);
	pthread_mutex_lock(&sim->mutex_start);
	while (sim->start_time == 0)
	{
		pthread_mutex_unlock(&sim->mutex_start);
		usleep(50);
		pthread_mutex_lock(&sim->mutex_start);
	}
	pthread_mutex_unlock(&sim->mutex_start);
}

int	usleep_check(t_sim *sim, long long action_duration)
{
	long long	start_time;
	long long	current_time;

	start_time = get_time_ms();
	while (1)
	{
		if (check_death(sim) == 1)
			return (1);
		current_time = get_time_ms();
		if ((current_time - start_time) >= action_duration)
			return (0);
		usleep(50);
	}
}

int	print_action(t_sim *sim, t_philo *philo, char *str)
{
	long long	current_time;

	pthread_mutex_lock(&sim->mutex_print);
	if (check_death(sim) == 1)
	{
		pthread_mutex_unlock(&sim->mutex_print);
		return (1);
	}
	current_time = get_time_ms() - sim->start_time;
	printf("%lld %d %s\n", current_time, philo->id, str);
	pthread_mutex_unlock(&sim->mutex_print);
	if (check_death(sim) == 1)
		return (1);
	return (0);
}

int	nb_meals_eaten(t_sim *sim, t_philo *philo)
{
	if (philo->nb_meal >= sim->nb_time_eat && sim->nb_time_eat > 0)
	{
		pthread_mutex_lock(&sim->mutex_total_meal);
		sim->total_meal++;
		pthread_mutex_unlock(&sim->mutex_total_meal);
		return (1);
	}
	return (0);
}
