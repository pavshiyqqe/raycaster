/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:18:45 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/19 18:30:35 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

char	*ft_remove_newline(char *str)
{
	char	*str2;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str2 = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			str2[j++] = str[i];
		i++;
	}
	str2[j] = '\0';
	return (str2);
}
