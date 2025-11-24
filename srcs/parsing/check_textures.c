/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromanov <rromanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:52:13 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/19 18:32:58 by rromanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header/cub3D.h"

static char	*check_acces(char *line_path, char *where)
{
	int		fd;
	char	*path;

	path = ft_remove_newline(line_path);
	if (!check_extension(path, ".xpm"))
		return (free(path), NULL);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
	{
		ft_putstr_fd("Invalid path of texture ", 2);
		ft_putendl_fd(where, 2);
		return (NULL);
	}
	close(fd);
	return (ft_strdup(line_path));
}

static bool	set_texture(t_data *d, char **s, int idx)
{
	if (idx == 0 && !d->north->path)
		d->north->path = check_acces(s[1], "north");
	else if (idx == 1 && !d->south->path)
		d->south->path = check_acces(s[1], "south");
	else if (idx == 2 && !d->west->path)
		d->west->path = check_acces(s[1], "west");
	else if (idx == 3 && !d->east->path)
		d->east->path = check_acces(s[1], "east");
	else
		return (false);
	return (true);
}

static int	get_tex_idx(char *key)
{
	if (!ft_strncmp(key, "NO", 3))
		return (0);
	if (!ft_strncmp(key, "SO", 3))
		return (1);
	if (!ft_strncmp(key, "WE", 3))
		return (2);
	if (!ft_strncmp(key, "EA", 3))
		return (3);
	return (-1);
}

bool	valide_texture(t_data *data, char *line)
{
	char	**sep;
	int		idx;

	sep = ft_split(line, ' ');
	if (!sep || check_number(sep) != 2)
		return (free_tab(sep), true);
	idx = get_tex_idx(sep[0]);
	if (idx == -1)
		return (free_tab(sep), true);
	if (!set_texture(data, sep, idx))
		return (ft_putendl_fd("Error texture", 2), free_tab(sep), false);
	return (free_tab(sep), true);
}

bool	check_textures_colors(t_data *data, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	while (map->initial_map[i])
	{
		line = map->initial_map[i];
		if (!valide_texture(data, line))
			return (false);
		if (!valide_color(map, line))
			return (false);
		i++;
	}
	if (!data->north->path || !data->south->path
		|| !data->west->path || !data->east->path)
		return (ft_putendl_fd("Missing texture", 2), false);
	if (map->f_color == -1 || map->c_color == -1)
		return (ft_putendl_fd("Missing color", 2), false);
	return (true);
}
