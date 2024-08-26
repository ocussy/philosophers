/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:01 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/24 11:37:57 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			len += choose_print(str, &args);
		}
		else
		{
			ft_putchar(*str);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}
