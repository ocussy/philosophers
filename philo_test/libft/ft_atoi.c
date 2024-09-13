/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:29:10 by ocussy            #+#    #+#             */
/*   Updated: 2024/06/11 12:19:28 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

/*int	main(void)
{
	const char *s1;
	const char *s2;

	s1 = "      +-45r4fsfewc5";
	s2 = "      +-45r4fsfewc5";
	printf("Result ft_atoi: %d \n", ft_atoi(s1));
	printf("Result normal atoi: %d", atoi(s2));
	return (0);
}*/
