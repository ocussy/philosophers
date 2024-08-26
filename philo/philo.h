#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "libft/libft.h"

typedef struct s_philo
{
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;

} t_philo ;

void philo(char *nb_philo, char *time_to_die, char *time_to_eat, char *time_to_sleep);
void philo_option(char *nb_philo, char *time_to_die, char *time_to_eat, char *time_to_sleep, char *nb_time_eat);
int main(int argc, char **argv);

# endif