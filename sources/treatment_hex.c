/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:30:08 by yzena             #+#    #+#             */
/*   Updated: 2020/11/27 11:13:13 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		in_out_hexa(char *hexa, t_flags flags)
{
	int chars;

	chars = 0;
	if (flags.tochka >= 0)
		chars += treatment_width(flags.tochka - 1, ft_strlen(hexa) - 1, 1);
	chars += ft_putstr(hexa, ft_strlen(hexa));
	return (chars);
}

static int		out_hexa(char *hexa, t_flags flags)
{
	int chars;

	chars = 0;
	if (flags.minus == 1)
		chars += in_out_hexa(hexa, flags);
	if (flags.tochka >= 0 && (size_t)flags.tochka < ft_strlen(hexa))
		flags.tochka = ft_strlen(hexa);
	if (flags.tochka >= 0)
	{
		flags.width -= flags.tochka;
		chars += treatment_width(flags.width, 0, 0);
	}
	else
		chars += treatment_width(flags.width, ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		chars += in_out_hexa(hexa, flags);
	return (chars);
}

int				treatment_hex(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		chars;

	chars = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.tochka == 0 && ui == 0)
	{
		chars += treatment_width(flags.width, 0, 0);
		return (chars);
	}
	hexa = putnbr_base((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	chars += out_hexa(hexa, flags);
	free(hexa);
	return (chars);
}
