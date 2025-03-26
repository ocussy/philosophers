/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:12:03 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/14 09:12:05 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	while (s1[start] && ft_charset(s1[start], set))
		(start)++;
	end = ft_strlen(s1);
	while (end > start && ft_charset(s1[end - 1], set))
		(end)--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[(start)++];
	str[i] = '\0';
	return (str);
}
/*
#include "libft.h"

int    set_check(char c, char const *set)
{
    size_t    i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
		return (1);
	i++;
    }
    return (0);
}

char    *ft_strtrim(const char *s, const char *set)
{
    size_t    i;
    size_t    j;
    size_t        size;
    char    *str;

    i = 0;
    j = ft_strlen(s);
    size = 0;
    while (s[i] && set_check(s[i], set))
        (i)++;
    while (j > i && set_check(s[j - 1], set))
        (j)--;
    str = (char *)malloc(sizeof(char) * (j - i + 1));
    if (!str)
        return (NULL);
    while (i < j)
    {
        str[size] = s[i];
        size++;
        i++;
    }
    str[size] = '\0';
    return (str);
}*/
