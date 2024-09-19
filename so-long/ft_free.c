/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:45:24 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/24 15:29:34 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_lst(t_game *game)
{
	free(game->map);
	if (game->mlx)
		free(game->mlx);
}

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_lst(game);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
