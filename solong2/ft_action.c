/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:46:14 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 15:46:17 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_render(t_game *game)
{
	int	i;

	i = 100;
	game->w_img = mlx_xpm_file_to_image(game->mlx, "ast/wall.xpm", &i, &i);
	game->p_img = mlx_xpm_file_to_image(game->mlx, "ast/player.xpm", &i, &i);
	game->e_img = mlx_xpm_file_to_image(game->mlx, "ast/exit.xpm", &i, &i);
	game->c_img = mlx_xpm_file_to_image(game->mlx, "ast/coin.xpm", &i, &i);
	game->f_img = mlx_xpm_file_to_image(game->mlx, "ast/floor.xpm", &i, &i);
	if (!game->c_img || !game->f_img
		|| !game->p_img || !game->w_img || !game->e_img)
	{
		free(game->win);
		free(game->mlx);
		ft_printf("Error!\n");
		ft_putstr_fd("Image file is missing!\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_map_render(t_game *g, int i)
{
	char	*m;
	int		x;
	int		y;

	y = -1;
	while (++y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[i] == '1')
				m = g->w_img;
			if (g->map[i] == '0')
				m = g->f_img;
			if (g->map[i] == 'C')
				m = g->c_img;
			if (g->map[i] == 'E')
				m = g->e_img;
			if (g->map[i] == 'P')
				m = g->p_img;
			mlx_put_image_to_window(g->mlx, g->win, m, x * 100, y * 100);
			i++;
			x++;
		}
	}
}

void	ft_action(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 100 * game->width,
			100 * game->height, "SO_LONG");
	ft_img_render(game);
	ft_map_render(game, 0);
	mlx_hook(game->win, 17, 0, ft_close, game);
	mlx_key_hook(game->win, ft_key_hook, game);
	mlx_loop(game->mlx);
}
