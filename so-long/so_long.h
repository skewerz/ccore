/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:44:51 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/24 19:09:57 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_game
{
	int		width;
	int		bas;
	int		bosluk;
	int		height;
	int		player_count;
	int		exit_count;
	int		steps;
	int		score;
	int		max_score;
	int		gameover;
	char	*map;
	char	**path_map;
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*e_img;
	void	*w_img;
	void	*c_img;
	void	*f_img;
	char	*valid_map;
}	t_game;

void	start_game(char *map, t_game *game);
int		ft_extension_check(char *map_file);
void	ft_error(char *str, t_game *game);
void	ft_action(t_game *game);
void	creat_map(int fd, t_game *game);
int		ft_close(t_game *game);
void	ft_free_lst(t_game *game);
void	ft_map_render(t_game *game, int i);
void	ft_img_render(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
void	ft_wkey(t_game *game);
void	ft_skey(t_game *game);
void	ft_dkey(t_game *game);
void	ft_akey(t_game *game);
int		valid_path_control(char *map, t_game *game);
void	free_map(char **map);
int		ft_hesap(char *str, int *i);
int		skipempty(char *str);
int		test(char *str, t_game *game);
void	legal_file(char *map, t_game *game);
void	create_str(t_game *game, char *line);
void	checkmap2(t_game *game, char *map);

#endif
