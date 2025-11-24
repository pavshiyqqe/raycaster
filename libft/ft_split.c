/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:13 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:39:13 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

unsigned int	ft_number_strings(char const *s, char c)
{
	unsigned int	count;
	unsigned int	index;

	count = 0;
	index = 0;
	if (!s[0])
		return (0);
	while (s[index] && s[index] == c)
		index++;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			if (s[index - 1] != c)
				count++;
			if (s[index] && s[index] == c)
				index++;
			continue ;
		}
		index++;
	}
	if (s[index - 1] != c)
		count++;
	return (count);
}

void	ft_mns(char const **nxt_str, unsigned int *nxt_str_len, char c)
{
	unsigned int	index;

	*nxt_str += *nxt_str_len;
	*nxt_str_len = 0;
	index = 0;
	while (**nxt_str && **nxt_str == c)
	{
		(*nxt_str)++;
	}
	while ((*nxt_str)[index])
	{
		if ((*nxt_str)[index] == c)
		{
			return ;
		}
		(*nxt_str_len)++;
		index++;
	}
}

static char	**ft_free_split(char **res, unsigned int index)
{
	while (index > 0)
	{
		index--;
		free(res[index]);
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	char			*next_string;
	unsigned int	next_string_length;
	unsigned int	number_strings;
	unsigned int	index;

	number_strings = ft_number_strings(s, c);
	res = (char **)malloc(sizeof(char *) * (number_strings + 1));
	if (!res || !s)
		return (NULL);
	index = 0;
	next_string = (char *)s;
	next_string_length = 0;
	while (index < number_strings)
	{
		ft_mns((const char **)&next_string, &next_string_length, c);
		res[index] = (char *)malloc(sizeof(char) * next_string_length + 1);
		if (!res[index])
			return (ft_free_split(res, index));
		ft_strlcpy(res[index], next_string, next_string_length + 1);
		index++;
	}
	res[index] = NULL;
	return (res);
}
