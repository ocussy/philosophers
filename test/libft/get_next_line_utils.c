/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:42:02 by ocussy            #+#    #+#             */
/*   Updated: 2024/04/19 16:32:02 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	update_lst(t_gnl **lst, char *buff)
{
	t_gnl	*new;
	t_gnl	*tmp;

	new = malloc(sizeof(t_gnl));
	if (!new)
		return (1);
	new->content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (new->content == NULL)
	{
		free(new);
		return (1);
	}
	ft_memset(new->content, 0, BUFFER_SIZE);
	ft_strncat(new->content, buff, BUFFER_SIZE + 1);
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

char	*ft_lst_clear(t_gnl **lst)
{
	t_gnl	*tmp;
	t_gnl	*ptr;

	ptr = *lst;
	if (!lst)
		return (NULL);
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr->content);
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
	return (NULL);
}

void	ft_strncat(char *dest, char *src, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i] && i < n - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	while (i < n)
	{
		dest[j] = 0;
		i++;
		j++;
	}
	return ;
}

int	ft_strlen_cs(char *str, char c, int f)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (f && str[i] == c)
		i++;
	return (i);
}

// void	ft_memset(char *str, int c, int n)
// {
// 	while (n)
// 	{
// 		*str++ = c;
// 		n--;
// 	}
// 	return ;
// }

// void	ft_memset(char *str, int c, int n)
// {
// 	while (n)
// 	{
// 		*str++ = c;
// 		n--;
// 	}
// 	return ;
// }

// size_t	ft_strlen(const char *theString)
// {
// 	int	i;

// 	i = 0;
// 	while (theString[i])
// 		i++;
// 	return (i);
// }

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	ft_strchr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 	{
// 		if (s[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	char	*str;
// 	size_t	i;

// 	str = (char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		str[i] = '\0';
// 		i++;
// 	}
// }

// char	*ft_strjoin_gnl(char *s1, char *s2)
// {
// 	char	*str;
// 	int		total_len;
// 	int		i;
// 	int		j;

// 	i = -1;
// 	j = 0;
// 	if (!s1)
// 		s1 = ft_calloc(1, 1);
// 	if (!s1)
// 		return (NULL);
// 	total_len = ft_strlen(s1) + ft_strlen(s2);
// 	str = malloc((total_len + 1) * sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	while (s1[++i])
// 		str[i] = s1[i];
// 	while (s2[j])
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_make_join(char *line, char *buf)
// {
// 	char	*tmp;

// 	tmp = ft_strjoin_gnl(line, buf);
// 	free(line);
// 	return (tmp);
// }
