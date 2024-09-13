/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:12:10 by ocussy            #+#    #+#             */
/*   Updated: 2024/09/13 16:54:03 by ocussy           ###   ########.fr       */
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

typedef struct s_info
{
	char			*nb_philo;
	char			*time_to_die;
	char			*time_to_eat;
	char			*time_to_sleep;
	char			*nb_time_eat;
}					t_info;

struct	s_sim;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		last_eat;
	int				nb_meal;
	struct t_sim	*sim;
}					t_philo;

typedef struct s_sim
{
	t_philo			philo[255];
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_eat;
	int				total_meal;
	pthread_t		philosophers[255];
	pthread_t		monitoring_thread;
	long long		start_time;
	bool			is_dead;
	pthread_mutex_t	forks[255];
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	mutex_add_meal;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_start;
	pthread_mutex_t	mutex_total_meal;
	int				ready;
}					t_sim;

// philo

void				routine_philo(t_sim *sim, t_philo *philo);
int					check_philo_status(t_sim *sim, t_philo *philo);
void				*philosopher(void *arg);
void				philo(t_info *info);

// monitor

int					check_all_eaten(t_sim *sim);
int					check_death(t_sim *sim);
void				print_death(t_sim *sim, int i);
int					monitor_death(t_sim *sim);
void				*monitoring(void *arg);

// eat

int					take_forks(t_sim *sim, t_philo *philo,
						pthread_mutex_t *first_fork,
						pthread_mutex_t *second_fork);
int					eat_action(t_sim *sim, t_philo *philo,
						pthread_mutex_t *first_fork,
						pthread_mutex_t *second_fork);
int					eat_even(t_sim *sim, t_philo *philo);
int					eat_odd(t_sim *sim, t_philo *philo);

// utils

long long			get_time_ms(void);
void				wait_philo(t_sim *sim);
int					usleep_check(t_sim *sim, long long action_duration);
int					print_action(t_sim *sim, t_philo *philo, char *str);
int					nb_meals_eaten(t_sim *sim, t_philo *philo);

// init_philo

void				clean_simulation(t_sim *sim);
void				start_simulation(t_sim *sim);
void				init_philosophers_args(t_sim *sim, t_philo *philo,
						pthread_mutex_t *fork);
int					init_simulation(t_sim *sim, t_info *info);

// verif_data

int					verif_philo(char *nb_philo);
int					verif_time_and_zero(char *time);
int					verif_time(char *nb);
int					verif_argument(char *time_to_die, char *time_to_eat,
						char *time_to_sleep, char *nb_time_eat);

// main

void				print_help(void);
void				init_info(t_info *info);
int					main(int argc, char **argv);

#endif