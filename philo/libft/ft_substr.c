/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:12:08 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/14 09:12:09 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > (len_s - start))
		len = len_s - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

/*int main() {
	const char *originalString = "ABCDEF";
	unsigned int start = 1; // Indice de début
	size_t length = 3; // Longueur de la sous-chaîne

	// Utilisation de la fonction ft_substr personnalisée
	char *subString = ft_substr(originalString, start, length);

	if (subString) {
		printf("Chaîne originale : %s\n", originalString);
		printf("Sous-chaîne (ft_substr) : %s\n", subString);

		// N'oubliez pas de libérer la mémoire allouée
		free(subString);
	} else {
		printf("Erreur lors de la création de la sous-chaîne.\n");
	}

	return (0);
}*/
