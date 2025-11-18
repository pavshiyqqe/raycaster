/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:09 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:39:09 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
 *  The strchr() function returns a pointer 
 *  to the first occurrence of the character c in the string s.
*/

#include "libft.h"
#include <stddef.h>
#include<string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

/*
int	main(void)
{
	char *res;
	char s[] = "tripouille";

	//res = ft_strchr(s, 't'); //  == s);
	//res = ft_strchr(s, 'l'); // == s + 7);
	//res = ft_strchr(s, 'z'); // == 0);
	res = ft_strchr(s, 0); //  == s + strlen(s));
	//res = ft_strchr(s, 't' + 256); // == s);
	return (0);
}*/
