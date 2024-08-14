/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:12:35 by ocussy            #+#    #+#             */
/*   Updated: 2024/08/13 16:42:18 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

#define TIMES_TO_COUNT 21000
#define NC "\e[0m"
#define YELLOW "\e[1;33m"
#define BYELLOW "\e[1;33m"
#define RED "\e[31m"
#define GREEN "\e[32m"

typedef struct s_counter
{
	pthread_mutex_t	count_mutex;
	unsigned int	count;
}					t_counter;

void	*thread_routine(void *data)
{
	unsigned int	i;

	t_counter *counter; // pointeur vers la structure dans le main
	counter = (t_counter *)data;
	// On imprime me compte avant que le thread commence
	// Pour lire le count on verouille le mutex
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread : Compte au depart = %u.%s\n", YELLOW, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	i = 0;
	while (i < TIMES_TO_COUNT)
	{
		// Quand om itere TIMES_TO_COUNT on verouille le mutex
		pthread_mutex_lock(&counter->count_mutex);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
		i++;
	}
	// Pareil quand on imprime le compte final on lock puis unlock
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread : Compte final = %u.%s\n", BYELLOW, counter->count_mutex,
		NC);
	pthread_mutex_unlock(&counter->count_mutex);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	t_counter	counter;

	counter.count = 0;
	// Initialisation du mutex
	pthread_mutex_init(&counter.count_mutex, NULL);
	printf("Main : Le compte attendu est de %s%u%s\n", GREEN, 2
		* TIMES_TO_COUNT, NC);
	// Creation des threads
	pthread_create(&thread1, NULL, thread_routine, &counter);
	printf("Main : creation du premier thread %ld.\n", thread1);
	pthread_create(&thread2, NULL, thread_routine, &counter);
	printf("Main : creation du deuxieme thread %ld.\n", thread2);
	// Recuperation des threads
	pthread_join(thread1, NULL);
	printf("Union du premier thread %ld.\n", thread1);
	pthread_join(thread2, NULL);
	printf("Union du deuxieme thread %ld.\n", thread2);
	// Evaluation du compte final
	if (counter.count != (2 * TIMES_TO_COUNT))
		printf("%sMain : Erreur : Le compte final est de %u%s\n", RED,
			counter.count, NC);
	else
		printf("%sMain : Succes : Le compte final est de %u%s\n", GREEN,
			counter.count, NC);
	// On detruit le mutex a la fin du programme pour pas de dead lock
	pthread_mutex_destroy(&counter.count_mutex);
	return (0);
}
