/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyaniv <yyaniv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:29:48 by yyaniv            #+#    #+#             */
/*   Updated: 2025/09/03 14:03:48 by yyaniv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

bool	check_grid_map(t_map *map)
{
	if (!check_size_map(map) || !check_walls(map)
		|| !check_player_other_char(map))
	{
		return (false);
	}
	return (true);
}

bool	parsing(t_data *data)
{
	if (!map_is_valid(data, data->map))
	{
		return (false);
	}
	if (data->map->player == 1)
		find_player(data, data->map);
	return (true);
}
