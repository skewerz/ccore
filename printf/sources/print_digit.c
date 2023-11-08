/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:57:25 by kalturan          #+#    #+#             */
/*   Updated: 2023/11/09 00:28:58 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_digit(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (count = write(1, "-2147483648", 11));
	else if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
		count += print_digit(n);
		return (count);
	}
	else if (n > 9)
	{
		count += print_digit(n / 10);
		count += print_digit(n % 10);
		return (count);
	}
	else
		return (count = print_char(n + 48));
	return (count);
}
