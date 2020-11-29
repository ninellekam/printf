/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:44:31 by ninakamkia        #+#    #+#             */
/*   Updated: 2020/11/27 19:47:31 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	treatment_percent(t_flags flags)
{
	int chars;

	chars = 0;
	if (flags.minus == 1)
		chars += ft_putstr("%", 1);
	if (flags.tochka >= 0)
	{
		flags.width -= flags.tochka;
		chars += treatment_width(flags.width, 0, 0);
	}
	else
		chars += treatment_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		chars += ft_putstr("%", 1);
	return (chars);
}
