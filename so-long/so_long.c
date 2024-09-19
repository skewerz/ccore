/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:44:58 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/26 22:37:24 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_values(t_game *game)
{
	game->map = NULL;
	game->path_map = NULL;
	game->w_img = NULL;
	game->e_img = NULL;
	game->p_img = NULL;
	game->c_img = NULL;
	game->f_img = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->player_count = 0;
	game->exit_count = 0;
	game->gameover = 0;
	game->steps = 0;
	game->score = 0;
	game->max_score = 0;
	game->bas = 0;
	game->bosluk = 0;
	game->valid_map = NULL;
}

void	start_game(char *map, t_game *game)
{
	int	fd;

	if (!ft_extension_check(map))
		ft_error("Error!\nWrong map extension!\n", game);
	legal_file(map, game);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("Error!\nNo such file or directory!\n", game);
	creat_map(fd, game);
	close(fd);
	if (!valid_path_control(map, game))
		ft_error("Error!\nThere is not a valid path\n", game);
	ft_action(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_init_values(&game);
	if (argc == 2)
		start_game(argv[1], &game);
	else
		ft_printf("Error!\nIncorrect number of parameters!\n");
	return (0);
}
