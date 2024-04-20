/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:42:35 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 15:51:57 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_xx(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n < 16)
		return (count = write(1, &base[n], 1));
	else
	{
		count += print_xx(n / 16);
		count += print_xx(n % 16);
		return (count);
	}
	return (count);
}

int	print_pointer(void *i)
{
	int					count;
	unsigned long		a;

	count = 2;
	a = (unsigned long)i;
	write(1, "0x", 2);
	if (i == 0)
		return (count += print_digit(0));
	count += print_xx(a);
	return (count);
}
