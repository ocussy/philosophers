/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:32:05 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/11 11:32:06 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*copy_src;
	unsigned char	*copy_dest;

	i = 0;
	copy_src = (unsigned char *)src;
	copy_dest = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		copy_dest[i] = copy_src[i];
		i++;
	}
	return (dest);
}

/*int main()
{
char	csrc[] = "GeeksforGeeks";
char	cdest[100];
ft_memcpy(cdest, csrc, strlen(csrc)+1);
printf("Copied string is %s", cdest);

int		isrc[] = {10, 20, 30, 40, 50};
int		n = sizeof(isrc)/sizeof(isrc[0]);
int idest[n], i;
ft_memcpy(idest, isrc, sizeof(isrc));
printf("\nCopied array is ");
for (i=0; i<n; i++)
	printf("%d ", idest[i]);
return (0);
}*/
