/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:09:09 by kalturan          #+#    #+#             */
/*   Updated: 2023/10/10 13:06:19 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)b;
	while (len > 0)
	{
		*tmp = (unsigned char )c;
		tmp++;
		len--;
	}
	return (b);
}

#include <stdio.h>
#include <string.h>

int	main()
{
	char a[] = "skewerzzz";
	int b[] = {1, 2, 3, 4, 5};
	int c = 'X';
	int d = 7;
	size_t e = sizeof(b) / sizeof(b[0]);

//	ft_memset(b, d, e);
	ft_memset(b, 9, 3 * sizeof(int));

	int i = 0;
	while (i < 5)
	{
		printf("%d ",b[i]);
		i++;
	}

	return 0;
}
