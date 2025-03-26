/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:36:06 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/13 16:30:53 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_philo(char *nb_philo)
{
	int	i;

	i = 0;
	while (nb_philo[i])
	{
		if (ft_isdigit(nb_philo[i]) == 0 || nb_philo[0] == '0'
			|| ft_strlen(nb_philo) >= 10)
		{
			printf("Number of philosophers shound be a positive int above 0.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	verif_time_and_zero(char *time)
{
	int	i;

	i = 0;
	while (time[i])
	{
		if (ft_isdigit(time[i]) == 0 || time[0] == '0' || ft_strlen(time) >= 10)
		{
			printf("Time_to_die and time_to_eat should be");
			printf(" positive int numbers above 0\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	verif_time(char *nb)
{
	int	i;

	i = 0;
	while (nb[i])
	{
		if (ft_isdigit(nb[i]) == 0 || ft_strlen(nb) >= 10)
		{
			printf("Time_to_sleep and ");
			printf("number_of_times_each_philosophers_must_eat");
			printf(" should be positive int numbers\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	verif_argument(char *time_to_die, char *time_to_eat, char *time_to_sleep,
		char *nb_time_eat)
{
	if (verif_time_and_zero(time_to_die) == 0)
		return (0);
	if (verif_time_and_zero(time_to_eat) == 0)
		return (0);
	if (verif_time(time_to_sleep) == 0)
		return (0);
	if (nb_time_eat != NULL)
	{
		if (verif_time(nb_time_eat) == 0)
			return (0);
	}
	return (1);
}
