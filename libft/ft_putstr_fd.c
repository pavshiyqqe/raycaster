/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:18 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:39:18 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
int	ft_strlen(char *s)
{
	int	length;

	length = 0;
	while(s[length] != '\0')
	{
		length++;
	}
	return (length);
}
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	length;

	length = ft_strlen(s);
	write(fd, s, length);
}
/*
int	main(void)
{
	ft_putstr_fd("qwerty", 1);
	return(0);
}*/
