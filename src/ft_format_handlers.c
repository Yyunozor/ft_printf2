/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:34 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 17:18:00 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Handles character format specifier (%c)
 * @param fmt Pointer to format structure containing args and state
 * @return 1 on success
 */
int	x_char(t_format *fmt)
{
	char	c;

	c = va_arg(fmt->args, int);
	fmt->len += write(1, &c, 1);
	return (1);
}

/**
 * @brief Handles string format specifier (%s)
 * @param fmt Pointer to format structure containing args and state
 * @return 1 on success
 */
int	x_str(t_format *fmt)
{
	char	*str;

	str = va_arg(fmt->args, char *);
	if (!str)
		str = "(null)";
	while (*str)
		fmt->len += write(1, str++, 1);
	return (1);
}

/**
 * @brief Handles pointer format specifier (%p)
 * @param fmt Pointer to format structure containing args and state
 * @return 1 on success
 */
int	x_ptr(t_format *fmt)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(fmt->args, void *);
	fmt->len += write(1, "0x", 2);
	ft_putunbr_base(ptr, HEX_LOWER, 16, &fmt->len);
	return (1);
}

/**
 * @brief Handles percent format specifier (%%)
 * @return 1 on success
 */
int	x_percent(void)
{
	write(1, "%", 1);
	return (1);
}