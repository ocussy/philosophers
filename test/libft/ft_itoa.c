/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:31:07 by ocussy            #+#    #+#             */
/*   Updated: 2024/04/01 16:29:23 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_putstr_itoa(int nb, int len, char *str)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		str[i] = '-';
		nb = -nb;
	}
	i = len - 1;
	if (nb == 0)
		str[i] = '0';
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			len;

	nb = n;
	len = ft_len(nb);
	if (n == -2147483648)
	{
		str = (char *)malloc(12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	nb = n;
	str = ft_putstr_itoa(nb, len, str);
	str[len] = '\0';
	return (str);
}

/*#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_rev_str(char *str)
{
	int		i;
	int		true_size;
	int		size;
	char	temp;

	i = 0;
	size = ft_strlen(str);
	true_size = size / 2;
	while (i < true_size)
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
	str[size] = '\0';
	return (str);
}

static char	*ft_create_str(int n)
{
	int		i;
	int		neg;
	char	*str;
	size_t	len;

	i = 0;
	neg = 0;
	len = ft_nbrlen(n);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
				return (NULL);
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	while (n)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	if (neg == 1)
		str[i] = '-';
	return (ft_rev_str(str));
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		str = (char *)malloc(12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (ft_create_str(n));
}*/

/*int    main(void)
{
	int i = 0;
	int tab[5] = {-2147483648, 0, -42, 42, 2147483647};

	while (i < 5)
		printf("%s\n", ft_itoa(tab[i++]));

	return (0);
}*/
