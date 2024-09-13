/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:40:20 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/20 11:16:55 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ptr(long long ptr)
{
	char	*base;
	int		len;

	len = 0;
	if (!ptr)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	base = "0123456789abcdef";
	len += ft_putchar('0');
	len += ft_putchar('x');
	len += ft_putnbr_base_ptr(ptr, base);
	return (len);
}
