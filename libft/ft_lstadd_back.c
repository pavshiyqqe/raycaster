/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:37:40 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:37:40 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*search_last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	if (!lst || !new)
		return ;
	search_last = *lst;
	while (search_last->next)
		search_last = search_last->next;
	search_last->next = new;
}
