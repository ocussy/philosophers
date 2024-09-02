/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:03:00 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/02 11:39:41 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	*monitoring(void *arg)
{
	t_sim		*sim;
	int			i;
	int			all_eaten;
	long long	start_time;
	long long	current_time;

	sim = (t_sim *)arg;
	all_eaten = 0;
	start_time = get_time_ms();
	while (1)
	{
		i = 0;
		while (i < sim->philo_args->nb_philo)
		{
			pthread_mutex_lock(&sim->philo_args[i].status_mutex);
			current_time = get_time_ms() - start_time;
			if (sim->philo_args->time_to_die < (current_time
					- sim->philo_args[i].last_eat)
				&& sim->philo_args[i].status != IS_EATING)
			{
				printf("%lld %d died\n", current_time, i + 1);
				clean_simulation(sim);
				exit(1);
			}
			if (sim->philo_args[i].meals_eaten >= sim->philo_args->nb_time_eat
				&& sim->philo_args->nb_time_eat >= 0)
				all_eaten = 0;
			else
				all_eaten = 1;
			pthread_mutex_unlock(&sim->philo_args[i].status_mutex);
			i++;
		}
		if (all_eaten != 1)
		{
			clean_simulation(sim);
			exit(1);
		}
		usleep(10000);
	}
	return (NULL);
}

void	*philosopher(void *arg)
{
	t_philo		*args;
	int			philo_id;
	long long	ms;
	long long	start_time;
	int			tmp;

	args = (t_philo *)arg;
	philo_id = args->id;
	start_time = get_time_ms();
	tmp = 0;
	while (1)
	{
		if (philo_id % 2 == 0)
			eat_even(start_time, args, philo_id);
		if (philo_id % 2 == 1)
		{
			if (tmp == 0)
				tmp++;
			else
				eat_odd(start_time, args, philo_id);
		}
		if (args->meals_eaten >= args->nb_time_eat && args->nb_time_eat >= 0)
		{
			pthread_mutex_lock(&args->meal_mutex);
			args->philo_meal_end++;
			pthread_mutex_unlock(&args->meal_mutex);
			break ;
		}
		args->status = IS_THINKING;
		ms = get_time_ms() - start_time;
		printf("%lld %d is sleeping\n", ms, philo_id);
		usleep(args->time_to_sleep * 1000);
		ms = get_time_ms() - start_time;
		printf("%lld %d is thinking\n", ms, philo_id);
		usleep(10000);
	}
	return (NULL);
}

void	philo(t_info *info)
{
	t_sim	sim;
	int		i;

	i = 0;
	if ((verif_philo(info->nb_philo) == 0) && (verif_argument(info->time_to_die,
				info->time_to_eat, info->time_to_sleep, NULL) == 0))
		return ;
	i = init_simulation(&sim, info);
	if (i == -1)
		return ;
	start_simulation(&sim);
	clean_simulation(&sim);
	return ;
}
