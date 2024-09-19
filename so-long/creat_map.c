/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:46:22 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/24 15:29:50 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_sub(char *s1, char *s2)
{
	char	*new;
	char	*tmp;

	if (s1 == NULL)
		return (ft_strtrim(s2, "\n"));
	tmp = ft_strjoin(s1, s2);
	if (!tmp)
	{
		ft_printf("Error!\n");
		exit(EXIT_FAILURE);
	}
	new = ft_strtrim(tmp, "\n");
	free(tmp);
	return (new);
}

void	ft_check_map(t_game *game)
{
	int	line;
	int	col;

	line = game->width;
	while (line >= 0)
	{
		if (game->map[line] != '1')
			ft_error("Error!\nMap don't have close walls\n", game);
		line--;
	}
	line = game->width;
	col = ft_strlen(game->map);
	while (line >= 0)
	{
		if (game->map[col - 1] != '1')
			ft_error("Error!\nMap don't have close walls\n", game);
		line--;
		col--;
	}
	if (game->width > 52 || game->height > 28)
		ft_error("Error!\nMap will not fit to window!\n", game);
}

int	ft_check_line_sub(t_game *game, char **line, int i)
{
	if ((*line)[i] != '1')
	{
		free(*line);
		ft_error("Error!\nMap don't have close walls\n", game);
	}
	return (1);
}

int	ft_check_line(t_game *game, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = ft_check_line_sub(game, line, 0);
	while ((*line)[i + 1] != '\n' && (*line)[i + 1])
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
				&& (*line)[i] != 'E' && (*line)[i] != 'P')
		{
			free(*line);
			ft_error("Error!\nYou don't have the correct components\n", game);
		}
		i++;
	}
	i = i + ft_check_line_sub(game, line, i);
	tmp = game->map;
	game->map = ft_strjoin_sub(tmp, *line);
	free(tmp);
	free(*line);
	if (i != game->width && game->width != 0)
		ft_error("Error!\nMap is not retangle", game);
	*line = get_next_line(fd);
	game->height++;
	return (i);
}

void	creat_map(int fd, t_game *game)
{
	int		i;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("Error!\nMap is empty\n", game);
	while (line != NULL)
		game->width = ft_check_line(game, &line, fd);
	ft_check_map(game);
	i = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
			game->max_score++;
		if (game->map[i] == 'P')
			game->player_count++;
		if (game->map[i] == 'E')
			game->exit_count++;
		i++;
	}
	if (game->player_count != 1
		|| game->exit_count != 1 || game->max_score == 0)
		ft_error("Error\nYou don't have the correct components\n", game);
}
