/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:35:37 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/11 11:35:39 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (!src || size == 0)
	{
		if (size > 0)
			dest[0] = '\0';
		return (ft_strlen(src));
	}
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	src_len = ft_strlen(src);
	return (src_len);
}

/*
 * //while (src[i]) i++;
int	main(void) {
	char dest[20];
	char src[] = "Hello, World!";
	unsigned int size = 12;

	unsigned int copied = ft_strlcpy(dest, src, size);

	printf("Copied: %u\n", copied);
	printf("Destination: %s\n", dest);

	return (0);
}*/
