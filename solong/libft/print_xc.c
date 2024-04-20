/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:39:41 by kalturan          #+#    #+#             */
/*   Updated: 2024/04/20 15:52:15 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_xc(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n < 16)
		return (count = write(1, &base[n], 1));
	else
	{
		count += print_xc(n / 16);
		count += print_xc(n % 16);
		return (count);
	}
	return (count);
}
