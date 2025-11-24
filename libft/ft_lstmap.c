/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:40:06 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:40:06 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*response;
	t_list	*temp;
	void	*f_result;

	response = NULL;
	while (lst)
	{
		f_result = f(lst->content);
		temp = ft_lstnew(f_result);
		if (!temp)
		{
			del(temp);
			ft_lstclear(&response, del);
			return (NULL);
		}
		ft_lstadd_back(&response, temp);
		lst = lst->next;
	}
	return (response);
}
