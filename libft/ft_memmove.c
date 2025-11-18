/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:38 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:39:38 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#define BUF_SIZE = 20

void	*ft_memmove( void *dest, const void *source, size_t size )
{
	size_t		index;

	if (!source && !dest)
		return (0);
	index = 0;
	if ((size_t)dest - (size_t)source < (size_t)size)
	{
		index = size - 1;
		while (index < size)
		{
			((unsigned char *)dest)[index] = ((unsigned char *)source)[index];
			index--;
		}
	}
	else
	{
		while (index < size)
		{			
			((unsigned char *)dest)[index] = ((unsigned char *)source)[index];
			index++;
		}
	}
	return (dest);
}
