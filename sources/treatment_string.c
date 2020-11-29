/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:42:27 by ninakamkia        #+#    #+#             */
/*   Updated: 2020/11/27 19:42:41 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	out_str(char *str, t_flags flags)
{
	int chars;

	chars = 0;
	if (flags.tochka >= 0)
	{
		chars += treatment_width(flags.tochka, ft_strlen(str), 0);
		chars += ft_putstr(str, flags.tochka);
		return (chars);
	}
	else
	{
		chars += ft_putstr(str, ft_strlen(str));
		return (chars);
	}
	return (chars);
}

int	treatment_string(char *str, t_flags flags)
{
	int chars;

	chars = 0;
	if (!str)
		str = "(null)";
	if (flags.tochka >= 0 && (size_t)flags.tochka > ft_strlen(str))
		flags.tochka = ft_strlen(str);
	if (flags.minus == 1)
		chars += out_str(str, flags);
	if (flags.tochka >= 0)
		chars += treatment_width(flags.width, flags.tochka, 0);
	else
		chars += treatment_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		chars += out_str(str, flags);
	return (chars);
}
