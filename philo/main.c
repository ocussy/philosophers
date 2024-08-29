/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:03:08 by ocussy            #+#    #+#             */
/*   Updated: 2024/08/28 18:12:45 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_help(void)
{
	printf("Usage: ./program_name number_of_philosophers \
	time_to_die time_to_eat time_to_sleep \
	[number_of_times_each_philosopher_must_eat]\n");
	printf("Arguments:\n");
	printf("  number_of_philosophers (>= 1)          : \
	Number of philosophers and forks.\n");
	printf("  time_to_die (in milliseconds)          : \
	Time until a philosopher dies if they don't eat.\n");
	printf("  time_to_eat (in milliseconds)          : \
	Time it takes for a philosopher to eat.\n");
	printf("  time_to_sleep (in milliseconds)        : \
	Time a philosopher spends sleeping.\n");
	printf("  number_of_times_each_philosopher_must_eat (optional) : \
	Number of times each philosopher must eat before \
	the simulation stops.\n");
	printf("    If this argument is not provided,the \
	simulation stops when a philosopher dies.\n");
	printf("\nExamples:\n");
	printf("  ./program_name 5 800 200 200\n");
	printf("  ./program_name 5 800 200 200 5\n");
}

void	init_info(t_info *info)
{
	info->nb_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->nb_time_eat = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argv[1] != NULL && ft_strncmp(argv[1], "help", ft_strlen(argv[1])) == 0)
	{
		print_help();
	}
	else if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments.\n");
	}
	else
	{
		init_info(&info);
		info.nb_philo = argv[1];
		info.time_to_die = argv[2];
		info.time_to_eat = argv[3];
		info.time_to_sleep = argv[4];
		if (argc == 6)
			info.nb_time_eat = argv[5];
		else
			info.nb_time_eat = 0;
		philo(&info);
	}
	return (0);
}
