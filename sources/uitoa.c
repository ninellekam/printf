/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:08:28 by yzena             #+#    #+#             */
/*   Updated: 2020/11/27 22:46:37 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_len(long n)
{
	size_t	len;
	int		neg;

	len = 0;
	neg = 0;
	if (n < 0)
	{
		len++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char		*ft_signed_itoa(char *rtn, long number, int len, int isneg)
{
	if (number != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	isneg = 0;
	if (number < 0)
	{
		isneg++;
		number = -number;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (number % 10) + '0';
		number /= 10;
	}
	if (isneg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (number % 10) + '0';
	return (rtn);
}

char			*u_itoa(unsigned int n)
{
	int		len;
	char	*rtn;
	long	number;
	int		neg;

	number = n;
	len = ft_len(number);
	rtn = 0;
	neg = 0;
	if (!(rtn = ft_signed_itoa(rtn, number, len, neg)))
		return (0);
	return (rtn);
}
