/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:32:11 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/11 11:32:15 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*srccpy;
	unsigned char		*destcpy;
	unsigned int		i;

	srccpy = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	i = 0;
	if ((size_t)(destcpy - srccpy) < n && destcpy - srccpy > 0)
	{
		i = n - 1;
		while (i < n)
		{
			destcpy[i] = srccpy[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

/*int main() {
	char source[] = "Hello, World!";
	char dest[20];

	// Utilisation de votre fonction ft_memmove
	ft_memmove(dest, source, 13);

	printf("Résultat de ft_memmove : %s\n", dest);

	// Comparaison avec la fonction standard memmove de la bibliothèque C
	char standard_dest[20];
	memmove(standard_dest, source, 13);

	printf("Résultat de memmove : %s\n", standard_dest);

	return (0);
}*/
