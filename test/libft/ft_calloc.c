/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:30:32 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/11 11:30:33 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*int main() {
	size_t numElements = 5;
	size_t elementSize = sizeof(int);

	// Utilisation de la fonction ft_calloc personnalisée
	int *arr = (int *)ft_calloc(numElements, elementSize);

	if (arr) {
		printf("Tableau alloué avec ft_calloc :\n");
		for (size_t i = 0; i < numElements; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		// N'oubliez pas de libérer la mémoire allouée
		free(arr);
	} else {
		printf("Erreur lors de l'allocation de mémoire avec ft_calloc.\n");
	}

	// Utilisation de la fonction calloc standard pour comparer les résultats
	int *standardArr = (int *)calloc(numElements, elementSize);

	if (standardArr) {
		printf("(Fonction standard) Tableau alloué avec calloc :\n");
		for (size_t i = 0; i < numElements; i++) {
			printf("%d ", standardArr[i]);
		}
		printf("\n");

		// N'oubliez pas de libérer la mémoire allouée par calloc
		free(standardArr);
	} else {
		printf(
	"Erreur lors
	de l'allocation de mémoire avec la fonction standard calloc.\n");
	}

	return (0);
}*/
