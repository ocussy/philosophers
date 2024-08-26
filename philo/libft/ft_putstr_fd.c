/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geoffreybougueroua <geoffreybougueroua@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:35:02 by ocussy            #+#    #+#             */
/*   Updated: 2024/06/12 04:49:50 by geoffreybou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd == 0)
		return ;
	write(2, s, ft_strlen(s));
	// while (s[i] != '\0')
	// {
	// 	ft_putchar_fd(s[i], fd);
	// 	i++;
	// }
}
