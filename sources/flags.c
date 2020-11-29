/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:18:24 by yzena             #+#    #+#             */
/*   Updated: 2020/11/28 12:29:57 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width *= -1;
	}
	return (flags);
}

int			flag_tochka(const char *save, int start,
						t_flags *flags, va_list args)
{
	int	i;

	i = start;
	i++;
	if (save[i] == '*')
	{
		flags->tochka = va_arg(args, int);
		i++;
	}
	else
	{
		flags->tochka = 0;
		while (ft_isdigit(save[i]))
		{
			flags->tochka = (flags->tochka * 10) + (save[i++] - '0');
		}
	}
	if (flags->tochka < 0)
		flags->tochka = -1;
	return (i);
}
