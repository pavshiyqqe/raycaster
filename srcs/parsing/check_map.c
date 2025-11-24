/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:13:26 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/19 18:29:53 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	fill_copy_lines(t_map *map)
{
	int	i;

	i = 0;
	while (map->initial_map[i])
		i++;
	map->height = i;
	i = 0;
	while (map->initial_map[i])
	{
		if ((int)ft_strlen(map->initial_map[i]) > map->length)
			map->length = ft_strlen(map->initial_map[i]);
		i++;
	}
}

static int	count_lines(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(map->fd);
	while (line)
	{
		free(line);
		line = get_next_line(map->fd);
		i++;
	}
	return (i);
}

bool	extract_info(t_map *map)
{
	char	*line;
	int		i;
	int		nb_lines;

	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
		return (false);
	nb_lines = count_lines(map);
	close(map->fd);
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
		return (false);
	map->initial_map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map->initial_map)
		return (false);
	i = 0;
	line = get_next_line(map->fd);
	while (line)
	{
		map->initial_map[i++] = line;
		line = get_next_line(map->fd);
	}
	map->initial_map[i] = NULL;
	fill_copy_lines(map);
	return (true);
}

static bool	order_in_file(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\n')
			{
				if (ft_isalpha(map[i][j]))
					return (true);
				if (ft_isdigit(map[i][j]))
					return (false);
			}
		}
	}
	return (false);
}

bool	map_is_valid(t_data *data, t_map *map)
{
	if (!extract_info(map) || !order_in_file(map->initial_map))
		return (false);
	if (!check_textures_colors(data, map))
		return (false);
	if (!find_grid(map, map->initial_map))
		return (false);
	return (check_grid_map(map));
}
