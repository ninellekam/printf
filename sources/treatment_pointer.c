/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:24:02 by ninakamkia        #+#    #+#             */
/*   Updated: 2020/11/27 19:47:15 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	out(char *pointer, t_flags flags)
{
	int chars;

	chars = 0;
	chars += ft_putstr("0x", 2);
	if (flags.tochka >= 0)
	{
		chars += treatment_width(flags.tochka, ft_strlen(pointer), 1);
		chars += ft_putstr(pointer, flags.tochka);
	}
	else
		chars += ft_putstr(pointer, ft_strlen(pointer));
	return (chars);
}

int	treatment_pointer(unsigned long long p, t_flags flags)
{
	char	*pointer;
	int		chars;

	chars = 0;
	if (p == 0 && flags.tochka == 0)
	{
		if (flags.minus == 1)
			chars += ft_putstr("0x", 2);
		chars += treatment_width(flags.width - 2, 0, flags.zero);
		if (flags.minus == 0)
			chars += ft_putstr("0x", 2);
		return (chars);
	}
	pointer = putnbr_base(p, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.tochka < ft_strlen(pointer))
		flags.tochka = ft_strlen(pointer);
	if (flags.minus == 1)
		chars += out(pointer, flags);
	chars += treatment_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		chars += out(pointer, flags);
	free(pointer);
	return (chars);
}
