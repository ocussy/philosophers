/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:03:00 by ocussy            #+#    #+#             */
/*   Updated: 2024/08/26 17:28:49 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_info *info, t_data *data)
{
	data->nb_philo = ft_atoi(info->nb_philo);
	data->time_to_die = ft_atoi(info->time_to_die);
	data->time_to_eat = ft_atoi(info->time_to_eat);
	data->time_to_sleep = ft_atoi(info->time_to_sleep);
	if (info->nb_time_eat != 0)
		data->nb_time_eat = ft_atoi(info->nb_time_eat);
	else
		data->nb_time_eat = 0;
}

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*philosopher(void *arg)
{
	t_philo		*args;
	t_data		*data;
	int			philo_id;
	long long	ms;
	long long	start_time;

	args = (t_philo *)arg;
	philo_id = args->id;
	data = args->data;
	start_time = get_time_ms();
	// while (1)
	// {
	ms = get_time_ms() - start_time;
	printf("%lld %d is eating \n", ms, philo_id);
	usleep(data->time_to_eat * 1000);
	ms = get_time_ms() - start_time;
	printf("%lld %d is sleeping\n", ms, philo_id);
	// }
	return (NULL);
}

void	philo(t_info *info)
{
	t_data		data;
	pthread_t	philosophers[255];
	t_philo		philo_arg[255];
	int			i;

	i = 1;
	if ((verif_philo(info->nb_philo) == 0) && (verif_argument(info->time_to_die,
				info->time_to_eat, info->time_to_sleep, NULL) == 0))
		return ;
	init_data(info, &data);
	while (i <= data.nb_philo)
	{
		philo_arg[i].id = i;
		philo_arg[i].data = &data;
		pthread_create(&philosophers[i], NULL, philosopher, &philo_arg[i]);
		i++;
	}
	i = 1;
	while (i <= data.nb_philo)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}
	return ;
}
