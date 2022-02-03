/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:19:09 by ppeapod           #+#    #+#             */
/*   Updated: 2021/05/01 16:19:10 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*next;

	if (!lst || !del)
		return ;
	a = *lst;
	while (a)
	{
		next = a->next;
		ft_lstdelone(a, del);
		a = next;
	}
	*lst = NULL;
}
