/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:45 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 17:18:04 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Handles format specifiers and routes to appropriate handler functions
 * @param fmt Pointer to format structure containing args and state
 * @return Number of characters processed (1 on success, 0 on failure)
 */
static int	x_format(t_format *fmt)
{
	int	ret;

	ret = 0;
	if (fmt->type == 'c')
		ret = x_char(fmt);
	else if (fmt->type == 's')
		ret = x_str(fmt);
	else if (fmt->type == 'p')
		ret = x_ptr(fmt);
	else if (fmt->type == 'd' || fmt->type == 'i')
		ret = x_int(fmt);
	else if (fmt->type == 'u')
		ret = x_uint(fmt);
	else if (fmt->type == 'x')
		ret = x_hex(fmt, HEX_LOWER);
	else if (fmt->type == 'X')
		ret = x_hex(fmt, HEX_UPPER);
	else if (fmt->type == '%')
	{
		fmt->len += write(1, "%", 1);
		ret = 1;
	}
	return (ret);
}

/**
 * @brief Printf implementation that handles basic format specifiers
 * @param format Format string containing text and format specifiers
 * @param ... Variable arguments corresponding to format specifiers
 * @return Total number of characters printed, -1 on error
 */
int	ft_printf(const char *format, ...)
{
	t_format	fmt;
	int			i;

	if (!format)
		return (-1);
	fmt.len = 0;
	i = 0;
	va_start(fmt.args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			fmt.type = format[++i];
			x_format(&fmt);
		}
		else
			fmt.len += write(1, &format[i], 1);
		i++;
	}
	va_end(fmt.args);
	return (fmt.len);
}
