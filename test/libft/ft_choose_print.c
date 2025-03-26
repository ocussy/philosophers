/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:41:04 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/20 11:17:11 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_print(const char *str, va_list *args)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (*str == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (*str == 'p')
		len += ft_putnbr_ptr(va_arg(*args, unsigned long long));
	else if (*str == 'd')
		len += ft_putnbr_base(va_arg(*args, int), "0123456789");
	else if (*str == 'i')
		len += ft_putnbr_base(va_arg(*args, int), "0123456789");
	else if (*str == 'u')
		len += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789");
	else if (*str == 'x')
		len += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		len += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		len += ft_putchar('%');
	return (len);
}
