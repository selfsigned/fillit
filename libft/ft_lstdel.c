/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:24:38 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/28 20:49:32 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *node;
	t_list *tmp;

	node = *alst;
	while (node)
	{
		tmp = node->next;
		ft_lstdelone(&node, del);
		node = tmp;
	}
	*alst = NULL;
}
