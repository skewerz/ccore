/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:45:20 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 15:45:31 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		game->gameover++;
	else if (keycode == 13)
		ft_wkey(game);
	else if (keycode == 1)
		ft_skey(game);
	else if (keycode == 2)
		ft_dkey(game);
	else if (keycode == 0)
		ft_akey(game);
	if (game->gameover > 0)
		ft_close(game);
	mlx_clear_window(game->mlx, game->win);
	ft_map_render(game, 0);
	return (0);
}
