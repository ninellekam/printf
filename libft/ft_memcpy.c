/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:14:31 by yzena             #+#    #+#             */
/*   Updated: 2020/11/04 18:34:24 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	if (dest == NULL && src == NULL)
		return (dest);
	while (n--)
		*str1++ = *str2++;
	return (dest);
}
