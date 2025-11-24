/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromanov <rromanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:14:32 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:07:04 by rromanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	is_player(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

bool	check_top_bottom_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && !ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_bounds(char **map, int i, int j, int h)
{
	int	len;

	if (j == 0)
		return (true);
	len = ft_strlen(map[i]);
	if (j >= len - 1)
		return (true);
	if (i > 0 && (j >= (int)ft_strlen(map[i - 1])
			|| ft_isspace(map[i - 1][j])))
		return (true);
	if (i < h - 1 && map[i + 1] && (j >= (int)ft_strlen(map[i + 1])
			|| ft_isspace(map[i + 1][j])))
		return (true);
	if (ft_isspace(map[i][j - 1]) || ft_isspace(map[i][j + 1]))
		return (true);
	return (false);
}

bool	check_no_output(char **map)
{
	int	i;
	int	j;
	int	h;

	h = 0;
	while (map[h])
		h++;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]))
				if (check_bounds(map, i, j, h))
					return (false);
		}
	}
	return (true);
}
