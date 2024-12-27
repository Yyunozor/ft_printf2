/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:08:45 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/27 13:46:43 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct s_printf
{
	va_list	args;
	int		len;
	char	type;
}	t_printf;

int		ft_printf(const char *format, ...);
int		x_formats(t_printf *p, char type);
int		x_numbers(t_printf *p, char type);
int		x_nbr(unsigned long n, const char *base, int blen);

#endif