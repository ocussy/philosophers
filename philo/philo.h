/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:09:53 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/03 17:13:34 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define IS_EATING 1
# define IS_THINKING 0
# define IS_DEAD 2

typedef struct s_info
{
	char			*nb_philo;
	char			*time_to_die;
	char			*time_to_eat;
	char			*time_to_sleep;
	char			*nb_time_eat;
}					t_info;

typedef struct s_philo
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_eat;
	int				meals_eaten;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	status_mutex;
	pthread_mutex_t	*meal_mutex;
	int				status;
	long long		last_eat;
	int				philo_meal_end;
	int				is_dead;
	pthread_mutex_t	*printf_mutex;
	pthread_mutex_t	*mutex_dead;
	pthread_mutex_t	*add_meal;
	pthread_mutex_t	*last_meal;
}					t_philo;

typedef struct s_sim
{
	t_philo			philo_args[255];
	pthread_t		philosophers[255];
	pthread_t		monitoring_thread;
	int				nb_philo;
	pthread_mutex_t	forks[255];
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	add_meal;
	pthread_mutex_t	last_meal;
}					t_sim;
// verif_data

int					verif_philo(char *nb_philo);
int					verif_time_and_zero(char *time);
int					verif_time(char *nb);
int					verif_argument(char *time_to_die, char *time_to_eat,
						char *time_to_sleep, char *nb_time_eat);

// init_philo

void				init_philosophers_args(t_sim *sim, t_philo *philo_arg,
						pthread_mutex_t *fork, t_info *info);
void				start_simulation(t_sim *sim);
int					init_simulation(t_sim *sim, t_info *info);
void				clean_simulation(t_sim *sim);

// philo_action

// void				eat_even(long long start_time, t_philo *args, int philo_id);
// void				eat_odd(long long start_time, t_philo *args, int philo_id);

// philo
void				philo(t_info *info);
void				*philosopher(void *arg);
void				*monitoring(void *arg);
long long			get_time_ms(void);

int					main(int argc, char **argv);

#endif
