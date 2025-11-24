/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:34 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:39:35 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define BUF_SIZE 20

void	*ft_memset(void *dest, int c, size_t count)
{
	char	*res;

	res = dest;
	{
		while (count)
		{
			*res = (unsigned char)c;
			res++;
			count--;
		}
		return (dest);
	}
}
