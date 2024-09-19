/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:45:58 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/26 22:15:10 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, t_game *game)
{
	if (game->map)
		free(game->map);
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

int	skipempty(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == 9 || str[i] == 32)
			i++;
		else if (str[i] == '\n')
			return (1);
		else
			return (0);
	}
	return (1);
}

int	ft_hesap(char *str, int *i)
{
	int	j;

	j = 0;
	while (str[*i] == 9 || str[*i] == 32)
	{
		if (str[*i] == 32)
			j++;
		else if (str[*i])
			j += 4;
		*i += 1;
	}
	return (j);
}
