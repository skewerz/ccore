/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:21:34 by kalturan          #+#    #+#             */
/*   Updated: 2023/11/09 00:29:10 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += print_unsigned(n / 10);
		count += print_unsigned(n % 10);
		return (count);
	}
	else
		return (count = print_digit(n));
	return (count);
}
