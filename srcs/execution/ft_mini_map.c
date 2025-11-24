/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromanov <rromanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:29:48 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/18 22:52:09 by rromanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_draw_square(int x, int y, t_data *s, int color)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;
	int	size;

	size = (HEIGHT / s->map->height) / 5;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel_x = x * size + i + 17;
			pixel_y = y * size + j - 17;
			pixel_y += (HEIGHT - (s->map->height * size));
			ft_mlx_pixel_put(pixel_x, pixel_y, s->main, color);
			j++;
		}
		i++;
	}
}

static void	ft_draw_map_element(char element, int x, int y, t_data *store)
{
	if (element == WALL)
		ft_draw_square(x, y, store, store->map->c_color);
	else if (element == FLOOR)
		ft_draw_square(x, y, store, store->map->f_color);
}

static void	ft_calc_triangle_pts(t_data *s, double size, int *p)
{
	int	cx;
	int	cy;

	cx = s->player->x * ((HEIGHT / s->map->height) / 5) + 9;
	cy = s->player->y * ((HEIGHT / s->map->height) / 5) - 14
		+ (HEIGHT - (s->map->height * ((HEIGHT / s->map->height) / 5)));
	p[0] = cx + s->player->dir_x * size;
	p[1] = cy + s->player->dir_y * size;
	p[2] = cx + (s->player->dir_x * (size / 2))
		- (s->player->dir_y * (size / 2));
	p[3] = cy + (s->player->dir_y * (size / 2))
		+ (s->player->dir_x * (size / 2));
	p[4] = cx + (s->player->dir_x * (size / 2))
		+ (s->player->dir_y * (size / 2));
	p[5] = cy + (s->player->dir_y * (size / 2))
		- (s->player->dir_x * (size / 2));
}

static void	ft_draw_triangle(t_data *s, int color)
{
	double	size;
	int		p[6];

	size = 10.0;
	ft_calc_triangle_pts(s, size, p);
	ft_mlx_pixel_put(p[0], p[1], s->main, color);
	ft_mlx_pixel_put(p[2], p[3], s->main, color);
	ft_mlx_pixel_put(p[4], p[5], s->main, color);
}

void	ft_mini_map(t_data *store)
{
	int	y;
	int	x;

	y = -1;
	while (store->map->map_grid[++y])
	{
		x = -1;
		while (store->map->map_grid[y][++x])
			ft_draw_map_element(store->map->map_grid[y][x], x, y, store);
	}
	ft_draw_square(store->player->x, store->player->y, store, 0x000);
	ft_draw_triangle(store, 0x000);
}
