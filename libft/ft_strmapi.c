/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:38:27 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:38:27 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		size;
	int		index;

	index = 0;
	size = ft_strlen((char *)s);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res || !s || !f)
		return (NULL);
	while (s[index] != '\0')
	{
		res[index] = f(index, s[index]);
		index++;
	}
	res[index] = '\0';
	return (res);
}
