/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:42:35 by kalturan          #+#    #+#             */
/*   Updated: 2023/11/10 21:52:25 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_pointer(unsigned long int i)
{
	int				count;

	count = 2;
	write(1, "0x", 2);
	if (i == 0)
		return (count += print_digit(0));
	count += print_xl((unsigned int)i);
	return (count);
}
