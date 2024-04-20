/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:44:46 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 15:45:40 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd)
{
	char	*line;
	char	*holder;
	char	**map;

	holder = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = ft_strjoin(holder, line);
		free(line);
	}
	map = ft_split(holder, '\n');
	free(holder);
	return (map);
}

int	*start_pos(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)ft_calloc(2, sizeof(int));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	flood_map(t_game *game, int y, int x)
{
	if (!(x < 1 || y < 1 || x >= game->width || y >= game->height
			|| game->path_map[y][x] == '1' || game->path_map[y][x] == 'X'))
	{
		game->path_map[y][x] = 'X';
		flood_map(game, y + 1, x);
		flood_map(game, y - 1, x);
		flood_map(game, y, x + 1);
		flood_map(game, y, x - 1);
	}
}

int	check_flood(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'X'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_path_control(int fd, t_game *game)
{
	int	*pos;

	game->path_map = read_map(fd);
	pos = start_pos(game->path_map);
	flood_map(game, pos[0], pos[1]);
	if (!check_flood(game->path_map))
	{
		free(pos);
		free_map(game->path_map);
		return (0);
	}
	free(pos);
	free_map(game->path_map);
	return (1);
}
