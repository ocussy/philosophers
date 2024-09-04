/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:46:37 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/04 11:52:33 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	print_action(t_philo *philo, char *str, long long start_time)
{
	long long	ms;

	ms = get_time_ms() - start_time;
	pthread_mutex_lock(philo->mutex_dead);
	if (philo->is_dead == 0)
	{
		ms = get_time_ms() - start_time;
		pthread_mutex_lock(philo->printf_mutex);
		printf("%lld %d %s\n", ms, philo->id, str);
		pthread_mutex_unlock(philo->printf_mutex);
	}
	pthread_mutex_unlock(philo->mutex_dead);
}

void	set_death(t_philo *philo, int philo_id, long long start_time)
{
	int			i;
	long long	current_time;

	i = 0;
	current_time = get_time_ms() - start_time;
	pthread_mutex_lock(&philo->status_mutex);
	if (philo[philo_id - 1].status == IS_DEAD)
	{
		pthread_mutex_lock(philo->printf_mutex);
		printf("%lld %d died\n", current_time, philo_id);
		pthread_mutex_unlock(philo->printf_mutex);
	}
	pthread_mutex_unlock(&philo->status_mutex);
	while (i < philo->nb_philo)
	{
		pthread_mutex_lock(philo->mutex_dead);
		philo[i].is_dead = 1;
		pthread_mutex_unlock(philo->mutex_dead);
		i++;
	}
}

int	check_death(t_philo *philo, int philo_id, long long start_time)
{
	long long	current_time;
	int			i;

	i = 0;
	pthread_mutex_lock(&philo->status_mutex);
	current_time = get_time_ms() - start_time;
	// printf("%d\n", philo_id);
	// if (philo_id == 3)
	// {
	// 	printf("%lld\n", current_time - philo[philo->id - 1].last_eat);
	// }
	pthread_mutex_lock(philo->last_meal);
	if (current_time - philo[philo_id - 1].last_eat > philo[philo_id
		- 1].time_to_die && philo[philo_id - 1].status != IS_EATING)
	{
		philo[philo_id - 1].status = IS_DEAD;
		pthread_mutex_unlock(philo->last_meal);
		pthread_mutex_unlock(&philo->status_mutex);
		set_death(philo, philo_id, start_time);
		return (1);
	}
	pthread_mutex_unlock(philo->last_meal);
	pthread_mutex_unlock(&philo->status_mutex);
	return (0);
}

void	*monitoring(void *arg)
{
	t_sim		*sim;
	t_philo		*philo;
	int			all_eaten;
	int			i;
	long long	start_time;

	sim = (t_sim *)arg;
	philo = sim->philo_args;
	start_time = get_time_ms();
	while (1)
	{
		i = 0;
		all_eaten = 1;
		pthread_mutex_lock(philo->mutex_dead);
		if (philo[i].is_dead == 1)
		{
			pthread_mutex_unlock(philo->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(philo->mutex_dead);
		while (i < sim->nb_philo)
		{
			if (check_death(philo, philo[i].id, start_time) == 1)
				return (NULL);
			pthread_mutex_lock(&sim->add_meal);
			if (philo[i].meals_eaten < philo[i].nb_time_eat
				|| philo->nb_time_eat < 0)
				all_eaten = 0;
			pthread_mutex_unlock(&sim->add_meal);
			i++;
		}
		if (all_eaten == 1)
		{
			set_death(philo, philo->id, start_time);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

void	eat_even(t_philo *philo, long long start_time)
{
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork", start_time);
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork", start_time);
	pthread_mutex_lock(&philo->status_mutex);
	philo->status = IS_EATING;
	pthread_mutex_unlock(&philo->status_mutex);
	pthread_mutex_lock(philo->last_meal);
	philo->last_eat = get_time_ms() - start_time;
	pthread_mutex_unlock(philo->last_meal);
	print_action(philo, "is eating", start_time);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_lock(philo->add_meal);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->add_meal);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat_odd(t_philo *philo, long long start_time)
{
	// printf("%d\n", philo->id);
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork", start_time);
	if (philo->nb_philo == 1)
	{
		usleep(philo->time_to_die * 1200);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	usleep(1000);
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork", start_time);
	pthread_mutex_lock(&philo->status_mutex);
	philo->status = IS_EATING;
	pthread_mutex_unlock(&philo->status_mutex);
	pthread_mutex_lock(philo->last_meal);
	philo->last_eat = get_time_ms() - start_time;
	pthread_mutex_unlock(philo->last_meal);
	print_action(philo, "is eating", start_time);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_lock(philo->add_meal);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->add_meal);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philosopher(void *arg)
{
	t_philo		*philo;
	long long	start_time;

	philo = (t_philo *)arg;
	start_time = get_time_ms();
	if (philo->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(philo->mutex_dead);
		if (philo->is_dead == 1)
		{
			pthread_mutex_unlock(philo->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(philo->mutex_dead);
		if (philo->id % 2 == 0)
			eat_even(philo, start_time);
		else if (philo->id % 2 == 1)
			eat_odd(philo, start_time);
		if (philo->meals_eaten >= philo->nb_time_eat && philo->nb_time_eat >= 0)
		{
			pthread_mutex_lock(philo->meal_mutex);
			philo->philo_meal_end++;
			pthread_mutex_unlock(philo->meal_mutex);
			break ;
		}
		pthread_mutex_lock(&philo->status_mutex);
		philo->status = IS_THINKING;
		pthread_mutex_unlock(&philo->status_mutex);
		print_action(philo, "is sleeping", start_time);
		usleep(philo->time_to_sleep * 1000);
		print_action(philo, "is thinking", start_time);
		// if (philo->id % 2 == 1)
		// 	usleep(1000);
		// pthread_mutex_lock(philo->last_meal);
		// if (philo->id % 2 == 0 && (((get_time_ms() - start_time)
		// 			- philo->last_eat
		// 			+ philo->time_to_eat)) < philo->time_to_die)
		// 	usleep(philo->time_to_eat * 900);
		// pthread_mutex_unlock(philo->last_meal);
	}
	return (NULL);
}

void	philo(t_info *info)
{
	t_sim	sim;
	int		i;

	i = 0;
	if ((verif_philo(info->nb_philo) == 0) || (verif_argument(info->time_to_die,
				info->time_to_eat, info->time_to_sleep, NULL) == 0))
		return ;
	i = init_simulation(&sim, info);
	if (i == -1)
		return ;
	start_simulation(&sim);
	clean_simulation(&sim);
	return ;
}
