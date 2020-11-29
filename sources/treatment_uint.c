/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:42:02 by ninakamkia        #+#    #+#             */
/*   Updated: 2020/11/27 19:42:09 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	in_out_uint(char *unsi_int, t_flags flags)
{
	int chars;

	chars = 0;
	if (flags.tochka >= 0)
		chars += treatment_width(flags.tochka - 1, ft_strlen(unsi_int) - 1, 1);
	chars += ft_putstr(unsi_int, ft_strlen(unsi_int));
	return (chars);
}

int	out_uint(char *unsi_int, t_flags flags)
{
	int chars;

	chars = 0;
	if (flags.minus == 1)
		chars += in_out_uint(unsi_int, flags);
	if (flags.tochka >= 0 && (size_t)flags.tochka < ft_strlen(unsi_int))
		flags.tochka = ft_strlen(unsi_int);
	if (flags.tochka >= 0)
	{
		flags.width -= flags.tochka;
		chars += treatment_width(flags.width, 0, 0);
	}
	else
		chars += treatment_width(flags.width,
		ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		chars += in_out_uint(unsi_int, flags);
	return (chars);
}

int	treatment_uint(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;
	int		chars;

	chars = 0;
	unsi = (unsigned int)(4294967295 + 1
				+ unsi);
	if (flags.tochka == 0 && unsi == 0)
	{
		chars += treatment_width(flags.width, 0, 0);
		return (chars);
	}
	unsi_int = u_itoa(unsi);
	chars += out_uint(unsi_int, flags);
	free(unsi_int);
	return (chars);
}
