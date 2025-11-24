/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromanov <rromanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:14:21 by rromanov          #+#    #+#             */
/*   Updated: 2025/09/03 14:05:21 by rromanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static bool	is_valid_rgb_string(char *str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (false);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] != '\n')
		return (false);
	num = ft_atoi(str);
	return (num >= 0 && num <= 255);
}

int	check_number(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

static bool	check_duplicate_color(t_map *map, char c)
{
	if (c == 'F' && map->f_color != -1)
		return (ft_putendl_fd("Error: Duplicate F color", 2), false);
	if (c == 'C' && map->c_color != -1)
		return (ft_putendl_fd("Error: Duplicate C color", 2), false);
	return (true);
}

bool	extract_color(t_map *map, char c, char *line)
{
	char	**sep;
	int		i;

	sep = ft_split(line, ',');
	if (!sep || check_number(sep) != 3)
		return (free_tab(sep), false);
	i = -1;
	while (++i < 3)
	{
		if (!is_valid_rgb_string(sep[i]))
			return (free_tab(sep), false);
		map->rgb[i] = ft_atoi(sep[i]);
	}
	if (!check_duplicate_color(map, c))
		return (free_tab(sep), false);
	if (c == 'F')
		map->f_color = rgb_to_int(map->rgb[0], map->rgb[1], map->rgb[2]);
	else
		map->c_color = rgb_to_int(map->rgb[0], map->rgb[1], map->rgb[2]);
	return (free_tab(sep), true);
}

bool	valide_color(t_map *map, char *line)
{
	char	*sub;
	int		i;
	char	c;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	c = line[i++];
	if (c == '\n')
		return (true);
	if (c != 'F' && c != 'C')
		return (true);
	while (ft_isspace(line[i]))
		i++;
	sub = ft_substr(line, i, ft_strlen(line));
	if (extract_color(map, c, sub))
		return (free(sub), true);
	return (free(sub), false);
}
