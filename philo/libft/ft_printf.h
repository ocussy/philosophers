/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:12:26 by ocussy            #+#    #+#             */
/*   Updated: 2024/04/01 16:30:42 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	choose_print(const char *str, va_list *args);
int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr_base(long long nbr, char *base);
int	ft_putnbr_ptr(long long ptr);
int	ft_putstr(char *s);
int	ft_strlen_printf(const char *s);
int	ft_putnbr_base_ptr(unsigned long long nbr, char *base);

#endif
