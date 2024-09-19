/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:45:17 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 16:03:56 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wkey(t_game *game)
{
	int	x;
	int	i;

	x = game->width;
	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i - x] == 'E' && game->max_score == game->score)
	{
		game->gameover++;
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
	if (game->map[i - x] != '1' && game->map[i - x] != 'E')
	{
		if (game->map[i - x] == 'C')
			game->score++;
		game->map[i] = '0';
		game->map[i - x] = 'P';
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
}

void	ft_skey(t_game *game)
{
	int	x;
	int	i;

	x = game->width;
	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i + x] == 'E' && game->max_score == game->score)
	{
		game->gameover++;
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
	if (game->map[i + x] != '1' && game->map[i + x] != 'E')
	{
		if (game->map[i + x] == 'C')
			game->score++;
		game->map[i] = '0';
		game->map[i + x] = 'P';
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
}

void	ft_dkey(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i + 1] == 'E' && game->max_score == game->score)
	{
		game->gameover++;
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
	if (game->map[i + 1] != '1' && game->map[i + 1] != 'E')
	{
		if (game->map[i + 1] == 'C')
			game->score++;
		game->map[i] = '0';
		game->map[i + 1] = 'P';
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
}

void	ft_akey(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != 'P')
		i++;
	if (game->map[i - 1] == 'E' && game->max_score == game->score)
	{
		game->gameover++;
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
	if (game->map[i - 1] != '1' && game->map[i - 1] != 'E')
	{
		if (game->map[i - 1] == 'C')
			game->score++;
		game->map[i] = '0';
		game->map[i - 1] = 'P';
		game->steps++;
		ft_printf("Moves: %i\n", game->steps);
	}
}
