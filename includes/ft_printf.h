/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:30:57 by yzena             #+#    #+#             */
/*   Updated: 2020/11/27 19:57:33 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct		s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				tochka;
	int				star;
}					t_flags;

int					ft_printf(const char *format, ...);
int					is_in_flags_list(int c);
int					in_put_part_int(char *d_i, int save_i, t_flags flags);
int					is_in_type_list(int c);
int					flag_parse(const char *save, int i,
					t_flags *flags, va_list args);
int					flag_tochka(const char *save, int start,
					t_flags *flags, va_list args);
int					ft_putchar(int c);
int					ft_putstr(char *str, int prec);
int					treatment_pointer(unsigned long long ull, t_flags flags);
int					treatment_hex(unsigned int ui, int lower, t_flags flags);
int					treatment_uint(unsigned int unsi, t_flags flags);
int					treatment_int(int i, t_flags flags);
int					treatment_percent(t_flags flags);
int					treatment(int c, t_flags flags, va_list args);
int					treatment_width(int width, int minus, int has_zero);
int					treatment_pointer(unsigned long long p, t_flags flags);
int					treatment_char(char c, t_flags flags);
int					treatment_string(char *str, t_flags flags);
int					treatment_flags_types(const char *save, va_list args);
int					put_part_int(char *str, t_flags flags);
char				*u_itoa(unsigned int n);
char				*ft_str_tolower(char *str);
char				*putnbr_base(unsigned long long ull, int base);
t_flags				flag_minus(t_flags flags);
t_flags				flag_width(va_list args, t_flags flags);
t_flags				flag_digit(char c, t_flags flags);
t_flags				init_flags(void);

#endif
