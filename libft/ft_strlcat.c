/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:18:05 by kalturan          #+#    #+#             */
/*   Updated: 2023/10/12 20:45:11 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	printf("%zu", i);
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	printf("%lu\n", strlen(src));
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}


int	main()
{
	char a[11] = "asdf";
	char b[] = "xyz";
	printf("%zu\n", ft_strlcat(a, b, 8));
	printf("%zu\n", strlcat(a, b, 8));
}