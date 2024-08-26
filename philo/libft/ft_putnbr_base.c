/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:39:51 by ocussy            #+#    #+#             */
/*   Updated: 2024/04/01 16:29:49 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long nbr, char *base)
{
	unsigned int	len_base;
	int				len;

	len = 0;
	len_base = ft_strlen_printf(base);
	if (base != 0)
	{
		if (nbr < 0)
		{
			len += ft_putchar('-');
			nbr *= -1;
		}
		if (nbr >= len_base)
			len += ft_putnbr_base((nbr / len_base), base);
		ft_putchar(base[nbr % len_base]);
		len++;
	}
	return (len);
}
