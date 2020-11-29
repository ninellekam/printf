/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:18:09 by yzena             #+#    #+#             */
/*   Updated: 2020/11/27 19:07:13 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		treatment(int c, t_flags flags, va_list args)
{
	int chars;

	chars = 0;
	if (c == 'c')
		chars = treatment_char(va_arg(args, int), flags);
	else if (c == 's')
		chars = treatment_string(va_arg(args, char *), flags);
	else if (c == 'p')
		chars = treatment_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		chars = treatment_int(va_arg(args, int), flags);
	else if (c == 'u')
		chars += treatment_uint((unsigned int)va_arg(args, unsigned int),
		flags);
	else if (c == 'x')
		chars += treatment_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		chars += treatment_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		chars += treatment_percent(flags);
	return (chars);
}
