/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:31:11 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/17 12:35:59 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		uc;

	src = s;
	uc = c;
	while (n-- > 0)
	{
		if (*src == uc)
		{
			return ((void *)src);
		}
		src++;
	}
	return (NULL);
}
