/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:57:25 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 15:51:39 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
