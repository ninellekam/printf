/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:31:33 by yzena             #+#    #+#             */
/*   Updated: 2020/11/28 17:42:11 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		in_out_int(char *d_i, int save_i, t_flags flags, int ok)
{
	int chars;

	chars = 0;
	if (save_i < 0 && flags.tochka >= 0 && ok == 0)
	{
		ft_putstr("-", 1);
		chars++;
	}
	if (flags.tochka >= 0)
		chars += treatment_width(flags.tochka - 1, ft_strlen(d_i) - 1, 1);
	chars += ft_putstr(d_i, ft_strlen(d_i));
	return (chars);
}

int		out_int(char *d_i, int save_i, t_flags flags, int ok)
{
	int chars;

	chars = 0;
	if (flags.minus == 1)
		chars += in_out_int(d_i, save_i, flags, ok);
	if (flags.tochka >= 0 && (size_t)flags.tochka < ft_strlen(d_i))
		flags.tochka = ft_strlen(d_i);
	if (flags.tochka >= 0)
	{
		flags.width -= flags.tochka;
		chars += treatment_width(flags.width, 0, 0);
	}
	else
		chars += treatment_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		chars += in_out_int(d_i, save_i, flags, ok);
	return (chars);
}

int		neg_int(int *i, t_flags *flags, int *ok)
{
	int chars;

	chars = 0;
	if (*i < 0 && (flags->tochka >= 0 || flags->zero == 1))
	{
		if (flags->zero == 1 && flags->tochka == -1)
		{
			*ok = 1;
			ft_putstr("-", 1);
			chars++;
		}
		*i *= -1;
		flags->width--;
	}
	return (chars);
}

void	check_ok(int *ok, int *chars)
{
	if (*ok == 0)
	{
		*ok = 1;
		ft_putstr("-", 1);
		(*chars)++;
	}
}

int		treatment_int(int i, t_flags flags)
{
	char	*d_i;
	int		save_i;
	int		chars;
	int		ok;

	ok = 0;
	save_i = i;
	chars = 0;
	if (flags.tochka == 0 && i == 0)
	{
		chars += treatment_width(flags.width, 0, 0);
		return (chars);
	}
	chars += neg_int(&i, &flags, &ok);
	d_i = ft_itoa(i);
	if (i == -2147483648)
	{
		free(d_i);
		check_ok(&ok, &chars);
		d_i = ft_strdup("2147483648");
	}
	chars += out_int(d_i, save_i, flags, ok);
	free(d_i);
	return (chars);
}
