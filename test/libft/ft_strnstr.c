/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:11:51 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/15 11:40:15 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0 && !big)
		return (NULL);
	while (big[i] && little[j] && i < len)
	{
		if (big[i] == little[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (little[j] == '\0')
		return ((char *)&big[i - j]);
	else
		return (NULL);
}
/*#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen) {
	char    c;
	char    sc;
	size_t    len;

	c = *find;

	if (c != '\0')
	{
		find++;
		len = ft_strlen(find);

		while (*s && slen >= 1) {
			sc = *s;

			while (sc != c) {
				if (sc == '\0' || slen-- < 1)
					return (NULL);

				s++;
				sc = *s;
			}
			if (len > slen)
				return (NULL);

			if (ft_strncmp(s, find, len) == 0)
			{
				return ((char *)s);
			}

			s++;
			slen--;
		}
	}

	return (NULL);
}*/
