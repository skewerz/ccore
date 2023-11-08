/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:29:40 by kalturan          #+#    #+#             */
/*   Updated: 2023/11/09 00:29:16 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_xl(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n < 16)
		return (count = write(1, &base[n], 1));
	else
	{
		count += print_xl(n / 16);
		count += print_xl(n % 16);
		return (count);
	}
	return (count);
}
