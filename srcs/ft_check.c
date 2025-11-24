/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromanov <rromanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:14:32 by yyaniv            #+#    #+#             */
/*   Updated: 2025/11/19 18:05:32 by rromanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"
#include <sys/stat.h>

bool	ft_check_size_of_window(void)
{
	if (WIDTH >= 1920 || HEIGHT >= 1080)
		return (false);
	if (HEIGHT <= 100 || WIDTH <= 100)
		return (false);
	return (true);
}

bool	check_argv(int argc, char *filename)
{
	int			fd;
	struct stat	path_stat;

	if (argc != 2)
		return (false);
	if (stat(filename, &path_stat) == -1)
		return (false);
	if (S_ISDIR(path_stat.st_mode))
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	close (fd);
	if (!check_extension(filename, ".cub"))
		return (false);
	return (true);
}

bool	check_extension(char *filename, char *extension)
{
	int	i;
	int	j;
	int	fn_len;
	int	ext_len;

	fn_len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	if (fn_len <= ext_len)
		return (false);
	if (filename[fn_len - ext_len - 1] == '/')
		return (false);
	i = fn_len - 1;
	j = ext_len - 1;
	while (j >= 0)
	{
		if (filename[i] != extension[j])
			return (false);
		i--;
		j--;
	}
	return (true);
}
