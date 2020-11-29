/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_flags_types.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:48:30 by ninakamkia        #+#    #+#             */
/*   Updated: 2020/11/27 19:48:41 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			treatment_flags_types(const char *save, va_list args)
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
