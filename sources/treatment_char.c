/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:16:34 by yzena             #+#    #+#             */
/*   Updated: 2020/11/27 11:11:29 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		treatment_char(char c, t_flags flags)
{
	int chars;

	chars = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	if (flags.zero)
		chars = treatment_width(flags.width, 1, 1);
	else
		chars = treatment_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (chars + 1);
}
