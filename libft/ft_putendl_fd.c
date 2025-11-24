/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:39:26 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 11:39:27 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	length;

	length = ft_strlen(s);
	write(fd, s, length);
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	ft_putendl_fd("qwerty", 1);
}*/
