/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:35:33 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/15 11:04:02 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	k;
	unsigned int	i;
	unsigned int	j;

	k = size;
	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i] && k-- != 0)
		i++;
	while (src[j])
		j++;
	if (size <= i)
		return (j + size);
	else
		j = j + i;
	k = 0;
	while (src[k] && (i + 1) < size)
	{
		dest[i++] = src[k++];
	}
	dest[i] = '\0';
	return (j);
}

/*#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
		size_t  i;
		size_t  dlen;

		i = 0;
		dlen = ft_strlen(dst);
		while (src[i] && i < size)
				dst[dlen++] = src[i++];
		dst[dlen] = '\0';
		return (dlen);
}*/
/*
#include <stdio.h>

int	main(void)
{
		char dst[] = "";
		char src[] = "";
		size_t  i;

		i = ft_strlcat(dst, src, 4);
		printf("concatenation = %s\ntaille max = %zu\n",dst, i);
}*/

/*int	main(void)
{
	char	s1[100] = "Hello";
	const char	*s2 = " World!";
	size_t	size = 7;

	printf("%lu\n", ft_strlcat(s1, s2, size));
	printf("%s\n", s1);
	return (0);
}*/
