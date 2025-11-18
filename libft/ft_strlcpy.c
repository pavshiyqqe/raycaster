/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:38:30 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:38:30 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (!size)
		return (ft_strlen((char *)src));
	while (src[count] != '\0' && count < (size -1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen((char *)src));
}
