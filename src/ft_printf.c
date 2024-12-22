/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:45 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 18:00:36 by anpayot          ###   ########.fr       */
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
		ret = x_percent();
		if (ret != -1)
			fmt->len += 1;
	}
	return (ret);
}

static int	handle_write(int fd, const void *buf, size_t count, int *total_len)
{
	int	written;

	written = write(fd, buf, count);
	if (written == -1)
		return (-1);
	*total_len += written;
	return (1);
}

static int	process_format(const char *format, t_format *fmt, int *i)
{
	if (format[*i] == '%' && format[*i + 1])
	{
		fmt->type = format[++(*i)];
		return (x_format(fmt));
	}
	return (handle_write(1, &format[*i], 1, &fmt->len));
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
	int			ret;

	if (!format)
		return (-1);
	fmt.len = 0;
	i = 0;
	va_start(fmt.args, format);
	while (format[i])
	{
		ret = process_format(format, &fmt, &i);
		if (ret == -1)
			return (-1);
		i++;
	}
	va_end(fmt.args);
	return (fmt.len);
}
