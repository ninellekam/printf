/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:18:12 by yzena             #+#    #+#             */
/*   Updated: 2020/11/27 11:11:29 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putstr(char *str, int prec)
{
	int chars;

	chars = 0;
	while (str[chars] && chars < prec)
		ft_putchar(str[chars++]);
	return (chars);
}

int		ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

char	*ft_str_tolower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}
