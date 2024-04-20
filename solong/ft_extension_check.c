/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:45:51 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 15:45:54 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_extension_check(char *map_file)
{
	int		i;
	char	*file_extension;

	file_extension = ".ber";
	i = 0;
	while (ft_strlen(map_file) != 4 && map_file)
	{
		map_file++;
	}
	if (!map_file || *map_file == '\0')
		return (0);
	while (map_file[i])
	{
		if (map_file[i] != file_extension[i])
			return (0);
		i++;
	}
	return (1);
}
