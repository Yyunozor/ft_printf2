/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:34 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/24 23:41:15 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>

/**
 * @brief Convert number to string in specified base
 * @param n Number to convert
 * @param base Base string containing characters
 * @param blen Length of base
 * @param p Pointer to printf structure
 * @return Result of buffer addition or -1 on error
 */
int	convert_nb(unsigned long n, const char *base, int blen, t_printf *p)
{
	char	buf[21];
	char	*ptr;

	ptr = buf + sizeof(buf) - 1;
	*ptr = '\0';
	if (n == 0)
		*--ptr = base[0];
	while (n)
	{
		*--ptr = base[n % blen];
		n /= blen;
	}
	return (add_to_buffer(p, ptr, ft_strlen(ptr)));
}

/**
 * @brief Handle signed integer conversion
 * @param p Pointer to printf structure
 * @return Result of conversion or -1 on error
 */
static int	x_uint(t_printf *p)
{
	long	num;

	num = va_arg(p->args, int);
	if (num < 0)
	{
		if (add_to_buffer(p, "-", 1) < 0)
			return (-1);
		num = -num;
	}
	return (convert_nb(num, "0123456789", 10, p));
}

/**
 * @brief Handle numeric format specifiers (d, i, u, x, X)
 * @param p Pointer to printf structure
 * @param type Format specifier character
 * @return Result of number conversion or -1 on error
 */
int	x_numbers(t_printf *p, char type)
{
	if (type == 'd' || type == 'i')
		return (x_uint(p));
	if (type == 'u')
		return (convert_nb(va_arg(p->args, unsigned int),
				"0123456789", 10, p));
	if (type == 'x')
		return (convert_nb(va_arg(p->args, unsigned int),
				HEX_LOWER, 16, p));
	return (convert_nb(va_arg(p->args, unsigned int),
			HEX_UPPER, 16, p));
}
