#include "philo.h"

int main(int argc, char **argv)
{
    printf("%d\n", argc);
    if (argc < 5 || argc > 6)
    {
        printf("Mauvais nombre d'arguments.\n");
        return (0);
    }
    else
    {
        if (argc == 5)
            philo(argv[1], argv[2], argv[3], argv[4]);
        else if (argc == 6)
            philo_option(argv[1], argv[2], argv[3], argv[4], argv[5]);
    }
}