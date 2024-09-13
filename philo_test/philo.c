/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:12:00 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/13 16:54:36 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_philo(t_sim *sim, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (eat_even(sim, philo) == 1)
			return ;
	}
	else
	{
		if (eat_odd(sim, philo) == 1)
			return ;
	}
	if (print_action(sim, philo, "is sleeping") == 1)
		return ;
	if (usleep_check(sim, sim->time_to_sleep) == 1)
		return ;
	if (print_action(sim, philo, "is thinking") == 1)
		return ;
	if (sim->nb_philo % 2 == 1 && sim->time_to_eat >= sim->time_to_sleep)
		usleep_check(sim, sim->time_to_eat * 0.9);
}

int	check_philo_status(t_sim *sim, t_philo *philo)
{
	if (check_death(sim) == 1)
		return (1);
	if (nb_meals_eaten(sim, philo) == 1 || check_death(sim) == 1)
		return (1);
	return (0);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;
	t_sim	*sim;

	philo = (t_philo *)arg;
	sim = philo->sim;
	wait_philo(sim);
	if (philo->id % 2 == 1 && sim->nb_philo != 1)
		usleep_check(sim, sim->time_to_eat * 0.9);
	while (1)
	{
		if (check_philo_status(sim, philo) == 1)
			break ;
		routine_philo(sim, philo);
	}
	return (NULL);
}

void	philo(t_info *info)
{
	t_sim	sim;
	int		i;

	i = 0;
	if ((verif_philo(info->nb_philo) == 0) || (verif_argument(info->time_to_die,
				info->time_to_eat, info->time_to_sleep,
				info->nb_time_eat) == 0))
		return ;
	if (init_simulation(&sim, info) == 1)
		return ;
	start_simulation(&sim);
	clean_simulation(&sim);
	return ;
}
