/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:53 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 17:30:25 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Optimized base conversion using lookup table and buffer
 * @param n Number to print
 * @param base String containing characters for base conversion
 * @param blen Length of the base string
 * @param len Pointer to counter for characters printed
 */
void	ft_putunbr_base(unsigned long n, const char *base, int blen, int *len)
{
	char	buf[21];  // Max digits for 64-bit number in binary + null
	char	*ptr;

	ptr = &buf[20];
	*ptr = '\0';
	if (!n)
		*--ptr = base[0];
	while (n)
	{
		*--ptr = base[n % blen];
		n /= blen;
	}
	*len += write(1, ptr, &buf[20] - ptr);
}

/**
 * @brief Optimized integer handler with direct buffer manipulation
 * @param fmt Pointer to format structure containing args and state
 * @return 1 on success
 */
int	x_int(t_format *fmt)
{
	int		n;
	char	buf[12];  // Max digits for 32-bit int + sign + null
	char	*ptr;
	int		neg;

	n = va_arg(fmt->args, int);
	neg = n < 0;
	ptr = &buf[11];
	*ptr = '\0';
	if (!n)
		*--ptr = '0';
	while (n)
	{
		*--ptr = '0' + (neg ? -(n % 10) : (n % 10));
		n /= 10;
	}
	if (neg)
		*--ptr = '-';
	fmt->len += write(1, ptr, &buf[11] - ptr);
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
 * @brief Optimized hex conversion using lookup and buffer
 * @param fmt Pointer to format structure containing args and state
 * @param base String containing hex digits
 * @return 1 on success
 */
int	x_hex(t_format *fmt, const char *base)
{
	unsigned int	n;
	char		buf[9];  // 8 hex digits + null
	char		*ptr;
	int			i;

	n = va_arg(fmt->args, unsigned int);
	if (!n)
	{
		fmt->len += write(1, "0", 1);
		return (1);
	}
	ptr = &buf[8];
	*ptr = '\0';
	i = 0;
	while (n && i < 8)
	{
		*--ptr = base[n & 0xF];
		n >>= 4;
		i++;
	}
	fmt->len += write(1, ptr, &buf[8] - ptr);
	return (1);
}
