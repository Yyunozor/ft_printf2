/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:53 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 17:17:56 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Recursively prints number in given base
 * @param n Number to print
 * @param base String containing characters for base conversion
 * @param blen Length of the base string
 * @param len Pointer to counter for characters printed
 */
void	ft_putunbr_base(unsigned long n, const char *base, int blen, int *len)
{
	if (n >= (unsigned long)blen)
		ft_putunbr_base(n / blen, base, blen, len);
	*len += write(1, &base[n % blen], 1);
}

/**
 * @brief Handles integer format specifiers (%d, %i)
 * @param fmt Pointer to format structure containing args and state
 * @return 1 on success
 */
int	x_int(t_format *fmt)
{
	long	n;

	n = va_arg(fmt->args, int);
	if (n < 0)
	{
		fmt->len += write(1, "-", 1);
		n = -n;
	}
	ft_putunbr_base(n, "0123456789", 10, &fmt->len);
	return (1);
}

/**
 * @brief Handles unsigned integer format specifier (%u)
 * @param fmt Pointer to format structure containing args and state
 * @return 1 on success
 */
int	x_uint(t_format *fmt)
{
	unsigned int	n;

	n = va_arg(fmt->args, unsigned int);
	ft_putunbr_base(n, "0123456789", 10, &fmt->len);
	return (1);
}

/**
 * @brief Handles hexadecimal format specifiers (%x, %X)
 * @param fmt Pointer to format structure containing args and state
 * @param base String containing hex digits (lowercase or uppercase)
 * @return 1 on success
 */
int	x_hex(t_format *fmt, const char *base)
{
	unsigned int	n;

	n = va_arg(fmt->args, unsigned int);
	ft_putunbr_base(n, base, 16, &fmt->len);
	return (1);
}
