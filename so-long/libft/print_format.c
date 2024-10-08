/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:41:49 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 15:51:46 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(char s, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += print_char(va_arg(ap, int));
	else if (s == 's')
		count += print_str(va_arg(ap, char *));
	else if (s == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (s == 'd' || s == 'i')
		count += print_digit(va_arg(ap, int));
	else if (s == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (s == 'x')
		count += print_xl(va_arg(ap, unsigned int));
	else if (s == 'X')
		count += print_xc(va_arg(ap, unsigned int));
	else if (s == '%')
		count += write (1, "%", 1);
	else
		count += write (1, &s, 1);
	return (count);
}
