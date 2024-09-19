/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:57:59 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/26 22:38:02 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test(char *str, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = ft_hesap(str, &i);
	if (game->bosluk == 0)
	{
		game->bosluk = j;
	}
	else
	{
		if (j != game->bosluk)
			ft_error("Error\nInvalid Map!\n", game);
	}
	game->bas = i;
	while (str[i] >= 33 && str[i] <= 126)
		i++;
	game->width = i - game->bas;
	while (str[i] == 9 || str[i] == 32)
		i++;
	if (str[i] != '\n' && str[i] != '\0')
		return (0);
	return (1);
}

void	create_str(t_game *game, char *line)
{
	int		j;
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (game->width + 2));
	j = game->bas;
	while (i < game->width)
	{
		tmp[i] = line[j];
		j++;
		i++;
	}
	tmp[i++] = '\n';
	tmp[i] = '\0';
	game->valid_map = ft_strxjoin(game->valid_map, tmp);
	free(tmp);
}

int	function(char **line, int fd, t_game *game)
{
	free(*line);
	if (skipempty(*line))
	{
		*line = get_next_line(fd);
		if (!*line)
			return (0);
		if (!skipempty(*line) && *line != NULL)
			ft_error("Error\nInvalid map\n", game);
	}
	else if (test(*line, game) && *line != NULL)
	{
		create_str(game, *line);
		*line = get_next_line(fd);
	}
	else
	{
		close(fd);
		ft_error("Error\nInvalid map!\n", game);
	}
	return (1);
}

void	checkmap2(t_game *game, char *map)
{
	int		fd;
	char	*line;
	int		flag;

	flag = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nEmpty map!\n", game);
	while (skipempty(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		flag = function(&line, fd, game);
		if (!flag)
			break ;
	}
	free (line);
	close(fd);
}

void	legal_file(char *map, t_game *game)
{
	int	fd;
	int	i;

	i = 0;
	checkmap2(game, map);
	fd = open(map, O_TRUNC | O_RDWR);
	ft_putstr_fd(game->valid_map, fd);
	free (game->valid_map);
	close(fd);
}
