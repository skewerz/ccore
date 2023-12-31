/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalturan <kalturan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:24:35 by kalturan          #+#    #+#             */
/*   Updated: 2023/11/10 23:16:45 by kalturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int				print_char(int c);
int				print_str(char *s);
int				print_digit(int n);
int				print_xl(unsigned int n);
int				print_xc(unsigned int n);
int				print_unsigned(unsigned int n);
int				print_format(char s, va_list ap);
int				print_pointer(void *i);
int				ft_printf(const char *format, ...);

#endif