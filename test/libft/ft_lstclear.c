/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocussy <ocussy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:25:35 by ocussy            #+#    #+#             */
/*   Updated: 2023/11/15 11:59:06 by ocussy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*store;
	t_list	*new;

	if (!lst || !*lst || !del)
		return ;
	new = *lst;
	while (new)
	{
		store = new->next;
		ft_lstdelone(new, del);
		new = store;
	}
	*lst = NULL;
}
