/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:07:16 by ocussy            #+#    #+#             */
/*   Updated: 2024/04/01 16:30:57 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_ptr(unsigned long long nbr, char *base)
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
			len += ft_putnbr_base_ptr((nbr / len_base), base);
		ft_putchar(base[nbr % len_base]);
		len++;
	}
	return (len);
}
