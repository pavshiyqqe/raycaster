/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 02:35:19 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/19 18:30:12 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	find_start(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] == '1')
			return (i);
		i++;
	}
	return (-1);
}

int	find_end(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	while (i-- > 0)
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] == '1')
			return (i);
	}
	return (-1);
}

char	**extract_map(char **dirty, int start, int end)
{
	char	**map;
	int		i;

	i = 0;
	if (start == -1 || end == -1 || start > end)
		return (NULL);
	map = malloc(sizeof(char *) * (end - start + 2));
	if (!map)
		return (NULL);
	while (start <= end)
	{
		map[i] = ft_strdup(dirty[start]);
		if (!map[i])
		{
			free_tab(map);
			return (NULL);
		}
		i++;
		start++;
	}
	map[i] = NULL;
	return (map);
}

bool	find_grid(t_map *map, char **dirty_map)
{
	int	start;
	int	end;

	start = find_start(dirty_map);
	end = find_end(dirty_map);
	map->map_grid = extract_map(dirty_map, start, end);
	if (!map->map_grid)
		return (false);
	map->height = end - start + 1;
	return (true);
}
