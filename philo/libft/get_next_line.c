/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:54:37 by ocussy            #+#    #+#             */
/*   Updated: 2024/04/19 16:31:55 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*fill_str(char *stash, char *str, t_gnl *lst, int lst_size)
{
	t_gnl	*temp_node;
	int		len;

	temp_node = lst;
	len = ft_strlen_cs(stash, '\n', 1);
	ft_strncat(str, stash, len + 1);
	if (temp_node != NULL)
	{
		while (--lst_size)
		{
			ft_strncat(str, temp_node->content, BUFFER_SIZE + 1);
			temp_node = temp_node->next;
		}
		len = ft_strlen_cs(temp_node->content, '\n', 1);
		ft_strncat(str, temp_node->content, len + 1);
	}
	if (!update_stash(stash, temp_node))
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*update_stash(char *stash, t_gnl *temp_str_node)
{
	char	*temp_str;
	int		len_to_trim;

	temp_str = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (temp_str == NULL)
		return (NULL);
	if (temp_str_node != NULL)
	{
		ft_memset(stash, 0, BUFFER_SIZE + 1);
		len_to_trim = ft_strlen_cs(temp_str_node->content, '\n', 1);
		ft_strncat(stash, temp_str_node->content + len_to_trim, (BUFFER_SIZE
				- len_to_trim + 1));
	}
	else
	{
		ft_memset(temp_str, 0, BUFFER_SIZE + 1);
		len_to_trim = ft_strlen_cs(stash, '\n', 1);
		ft_strncat(temp_str, stash + len_to_trim, BUFFER_SIZE - len_to_trim
			+ 1);
		ft_memset(stash, 0, BUFFER_SIZE + 1);
		ft_strncat(stash, temp_str, BUFFER_SIZE + 1);
	}
	free(temp_str);
	return (stash);
}

char	*handle_eol(int lst_size, char *stash, t_gnl *lst)
{
	t_gnl	*tmp;
	char	*str;
	int		i;
	int		len;

	i = 0;
	tmp = lst;
	if (tmp != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		i = ft_strlen_cs(tmp->content, '\n', 1);
	}
	len = ft_strlen_cs(stash, '\n', 1) + i + ((lst_size - 1) * BUFFER_SIZE);
	if (len == 0)
		return (ft_lst_clear(&lst));
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (ft_lst_clear(&lst));
	ft_memset(str, 0, len + 1);
	str = fill_str(stash, str, lst, lst_size);
	ft_lst_clear(&lst);
	return (str);
}

char	*read_till_eol(char *str, char *stash, t_gnl *lst, int fd)
{
	int		lst_size;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buff == NULL)
		return (NULL);
	lst_size = 0;
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	while (BUFFER_SIZE == read(fd, buff, BUFFER_SIZE) && ft_strlen_cs(buff,
			'\n', 0) == BUFFER_SIZE)
	{
		if (update_lst(&lst, buff))
			return (ft_lst_clear(&lst));
		lst_size++;
		ft_memset(buff, 0, BUFFER_SIZE + 1);
	}
	if (update_lst(&lst, buff))
		return (ft_lst_clear(&lst));
	lst_size++;
	str = handle_eol(lst_size, stash, lst);
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	stash[BUFFER_SIZE + 1];
	t_gnl		*lst;
	int			stash_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	lst = NULL;
	stash_len = ft_strlen_cs(stash, '\n', 0);
	if (*(stash + stash_len) == '\n')
		str = handle_eol(1, stash, lst);
	else
		str = read_till_eol(str, stash, lst, fd);
	return (str);
}

// void	*ft_calloc(size_t elementCount, size_t elementSize)
// {
// 	char	*res;

// 	res = malloc(elementSize * elementCount);
// 	if (!res)
// 		return (NULL);
// 	ft_bzero(res, elementSize * elementCount);
// 	return (res);
// }

// char	*ft_make_line(int fd, char *line)
// {
// 	char	*buf;
// 	int		count;

// 	if (!line)
// 		line = ft_calloc(1, 1);
// 	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buf)
// 		return (NULL);
// 	count = 1;
// 	while (count > 0)
// 	{
// 		count = read(fd, buf, BUFFER_SIZE);
// 		if (count == -1 || (count == 0 && line[0] == '\0'))
// 		{
// 			free(buf);
// 			free(line);
// 			return (NULL);
// 		}
// 		buf[count] = '\0';
// 		line = ft_make_join(line, buf);
// 		if (count != BUFFER_SIZE || ft_strchr(buf, '\n') != 0)
// 			break ;
// 	}
// 	free(buf);
// 	return (line);
// }

// char	*ft_get_line(char *tempo)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	if (!tempo)
// 		return (NULL);
// 	while (tempo[i] && tempo[i] != '\n')
// 		i++;
// 	line = ft_calloc((i + 2), sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (tempo[i] && tempo[i] != '\n')
// 	{
// 		line[i] = tempo[i];
// 		i++;
// 	}
// 	if (tempo[i] && tempo[i] == '\n')
// 	{
// 		line[i] = tempo[i];
// 		i++;
// 	}
// 	return (line);
// }

// char	*ft_clean(char *line)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	if (!line)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	while (line[i] != '\n' && line[i])
// 		i++;
// 	tmp = ft_calloc((ft_strlen(line) - i + 1), sizeof(char));
// 	if (!tmp)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	if (line[i] && line[i] == '\n')
// 		i++;
// 	while (line[i])
// 		tmp[j++] = line[i++];
// 	free(line);
// 	return (tmp);
// }

// char	*get_next_line(int fd)
// {
// 	char		*final_line;
// 	static char	*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line = ft_make_line(fd, line);
// 	if (!line || *line == '\0')
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	final_line = ft_get_line(line);
// 	line = ft_clean(line);
// 	return (final_line);
// }

// static char	*ft_join(char *s1, char *s2, char *str)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		str[j] = s1[i];
// 		j++;
// 		i++;
// 	}
// 	i = 0;
// 	while (s2[i])
// 	{
// 		str[j] = s2[i];
// 		j++;
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	return (ft_join(s1, s2, str));
// }

// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	char *buffer;

// 	buffer = get_next_line(0);
// 	while ((line = get_next_line(0)) != NULL)
// 	{
// 		buffer = ft_strjoin(buffer, line);
// 		free(line);
// 	}
// 	buffer = ft_strjoin(buffer, line);
// 	printf("%s\n", buffer);
// 	// free(buffer);
// 	return (0);
// }