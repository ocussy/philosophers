#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	char	*nb_philo;
	char	*time_to_die;
	char	*time_to_eat;
	char	*time_to_sleep;
	char	*nb_time_eat;
}			t_info;

typedef struct s_data
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_time_eat;

}			t_data;

typedef struct s_philo
{
	int		id;
	t_data	*data;
}			t_philo;

// verif_data

int			verif_philo(char *nb_philo);
int			verif_time_and_zero(char *time);
int			verif_time(char *nb);
int			verif_argument(char *time_to_die, char *time_to_eat,
				char *time_to_sleep, char *nb_time_eat);

void		philo(t_info *info);
void		philo_option(char *nb_philo, char *time_to_die, char *time_to_eat,
				char *time_to_sleep, char *nb_time_eat);
int			main(int argc, char **argv);

#endif