/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:39:08 by ninakamkia        #+#    #+#             */
/*   Updated: 2020/11/28 14:45:06 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags	init_flags(void)
{
	t_flags		flags;

	flags.tochka = -1;
	flags.minus = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int		flag_parse(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !is_in_type_list(save[i])
		&& !is_in_flags_list(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = flag_tochka(save, i, flags, args);
		if (save[i] == '-')
			*flags = flag_minus(*flags);
		if (save[i] == '*')
			*flags = flag_width(args, *flags);
		if (ft_isdigit(save[i]))
			*flags = flag_digit(save[i], *flags);
		if (is_in_type_list(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		treatment_flags_types(const char *save, va_list args)
{
	int			i;
	t_flags		flags;
	int			chars;

	i = 0;
	chars = 0;
	while (1)
	{
		flags = init_flags();
		if (!save[i])
			break ;
		else if (save[i] == '%' && save[i + 1])
		{
			i = flag_parse(save, ++i, &flags, args);
			if (is_in_type_list(save[i]))
				chars += treatment((char)flags.type, flags, args);
			else if (save[i])
				chars += ft_putchar(save[i]);
		}
		else if (save[i] != '%')
			chars += ft_putchar(save[i]);
		i++;
	}
	return (chars);
}

int		ft_printf(const char *format, ...)
{
	const char	*save;
	va_list		args;
	int			chars;

	save = ft_strdup(format);
	chars = 0;
	va_start(args, format);
	chars += treatment_flags_types(save, args);
	va_end(args);
	free((char *)save);
	return (chars);
}
