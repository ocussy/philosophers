/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:35:12 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/11 11:35:15 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

/*int main()
{
	const char *str = "Hello, World!";
	int search_char = 'e';

	char *result = ft_strchr(str, search_char);

	if (result) {
		printf
	("Le caractère '%c' a été trouvé dans la chaîne : %s\n",
		search_char, result);
	} else {
printf("Le caractère '%c' n'a pas été trouvé dans la chaîne : %s\n",
search_char, str);
	}

	return (0);
}*/
