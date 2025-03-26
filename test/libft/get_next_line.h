/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:12:28 by ocussy            #+#    #+#             */
/*   Updated: 2024/04/19 16:31:48 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct k_list
{
	char			*content;
	struct k_list	*next;
}					t_gnl;

char				*get_next_line(int fd);
char				*read_till_eol(char *str, char *stash, t_gnl *lst, int fd);
void				ft_strncat(char *dest, char *src, int n);
char				*update_stash(char *stash, t_gnl *tmp);
int					update_lst(t_gnl **lst, char *buff);
int					find_eol(char *buff);
char				*ft_lst_clear(t_gnl **lst);
int					ft_strlen_cs(char *str, char c, int f);
char				*fill_str(char *stash, char *str, t_gnl *lst,
						int lst_size);
// void				ft_memset(char *str, int c, int n);
#endif

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 2
// # endif

// # include <fcntl.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>

// // void	ft_bzero(void *s, size_t n);
// char	*ft_strjoin_gnl(char *s1, char *s2);
// char	*ft_make_join(char *line, char *buf);
// void	*ft_calloc(size_t elementCount, size_t elementSize);
// char	*ft_make_line(int fd, char *line);
// char	*ft_get_line(char *tempo);
// char	*ft_clean(char *line);
// char	*get_next_line(int fd);

// #endif