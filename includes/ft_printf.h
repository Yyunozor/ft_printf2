/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:08:45 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 17:14:03 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct s_format
{
	va_list	args;
	int		len;
	char	type;
	char	*str;
}	t_format;

int		ft_printf(const char *format, ...);
int		x_char(t_format *fmt);
int		x_str(t_format *fmt);
int		x_ptr(t_format *fmt);
int		x_int(t_format *fmt);
int		x_uint(t_format *fmt);
int		x_hex(t_format *fmt, const char *base);
int		x_percent(void);
void	ft_putunbr_base(unsigned long n, const char *base, int blen, int *len);

#endif