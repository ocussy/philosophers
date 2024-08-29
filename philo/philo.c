/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:03:00 by ocussy            #+#    #+#             */
/*   Updated: 2024/08/28 18:14:31 by ocussy           ###   ########.fr       */
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
	t_philo		*args;
	int			i;
	long long	start_time;
	long long	current_time;

	args = (t_philo *)arg;
	start_time = get_time_ms();
	while (1)
	{
		i = 0;
		while (i < args->nb_philo)
		{
			pthread_mutex_lock(&args[i].status_mutex);
			current_time = get_time_ms() - start_time;
			if (args->time_to_die < (current_time - args[i].last_eat)
				&& args[i].status != IS_EATING)
			{
				printf("%lld %d died\n", current_time, i + 1);
				exit(1);
			}
			pthread_mutex_unlock(&args[i].status_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	*philosopher(void *arg)
{
	t_philo		*args;
	int			philo_id;
	long long	ms;
	long long	start_time;

	args = (t_philo *)arg;
	philo_id = args->id;
	start_time = get_time_ms();
	while (1)
	{
		if (philo_id % 2 == 0)
			eat_even(start_time, args, philo_id);
		else if (philo_id % 2 == 1)
			eat_odd(start_time, args, philo_id);
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
	init_simulation(&sim, info);
	start_simulation(&sim);
	clean_simulation(&sim);
	return ;
}
