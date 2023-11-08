/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:42:35 by kalturan          #+#    #+#             */
/*   Updated: 2023/11/09 00:29:04 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_pointer(size_t i)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 2;
	write(1, "0x", 2);
	if (i == 0)
		return (count += print_digit(0));
	count += print_unsigned((unsigned int)i);
	return (count);
}
