/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:38:10 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:38:11 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			index;
	unsigned int	size_s;

	index = 0;
	size_s = ft_strlen((char *)s);
	if (size_s < len)
		len = size_s;
	if (size_s == 0 || start >= len + 1 || start > size_s)
		res = (char *)malloc(sizeof(char) * 1);
	else
		res = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !res)
	{
		return (NULL);
	}
	while (index < len && s[start] && start < size_s)
	{
		res[index] = s[start];
		start++;
		index++;
	}
	res[index] = '\0';
	return (res);
}
/*
int	main(void)
{
ft_substr("hola", 4294967295, 1);
return (0);
}*/
