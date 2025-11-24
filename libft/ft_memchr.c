/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:52 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:39:52 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*response;	

	index = 0;
	response = (unsigned char *)s;
	while (index < n)
	{
		if (response[index] == (unsigned char)c)
			return (&response[index]);
		index++;
	}
	return (NULL);
}
