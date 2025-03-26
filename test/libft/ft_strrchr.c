/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:11:56 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/14 09:11:58 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *cp, int ch)
{
	char	*save;

	save = NULL;
	while (*cp)
	{
		if (*cp == (char)ch)
			save = (char *)cp;
		cp++;
	}
	if (ch == '\0')
		return ((char *)cp);
	return (save);
}
/*#include "libft.h"

char	*ft_strrchr(const char *cp, int ch)
{
	char	*save;
	char	c;

	save = (char *)NULL;
	c = *cp;
	while (c != '\0')
	{
		if (c == ch)
			save = (char *)cp;
	c = *cp;
		cp++;
	}
	return (save);
}
*/
/*#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s)- 1;
	str = (char *) s;
	if (c == '\0')
		return (str);
	while (i > 0)
	{
		if (str[i] == c)
			return (str + i);
		i--;
	}
	return (NULL);
}
*/
/*#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (c == '\0')
		return((char *) s);
	while (i > 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}*/
/*int main()
{
	const char *str = "Hello, Worled!";
	int search_char = 'e';

	char *result = ft_strrchr(str, search_char);

	if (result) {
		printf("Le caractère '%c' a été trouvé dans la chaîne : %s\n",
		search_char, result);
	} else {
		printf("Le caractère '%c' n'a pas été trouvé dans la chaîne : %s\n",
		search_char, str);
	}

	return (0);
}*/
