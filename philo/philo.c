#include "philo.h"

void philo(char *nb_philo, char *time_to_die, char *time_to_eat, char *time_to_sleep)
{
    if (ft_atoi(nb_philo) == 0)
    {
        printf("Le nombre de philosophes doit être un entier ou plus grand que 0.\n");
    }
    (void)time_to_die;
    (void)time_to_eat;
    (void)time_to_sleep;
    return;
}

void philo_option(char *nb_philo, char *time_to_die, char *time_to_eat, char *time_to_sleep, char *nb_time_eat)
{
      if (ft_atoi(nb_philo) == 0)
    {
        printf("Le nombre de philosophes doit être un entier ou plus grand que 0.\n");
    }
    (void)time_to_die;
    (void)time_to_eat;
    (void)time_to_sleep;
    (void)nb_time_eat;
    return ;
}