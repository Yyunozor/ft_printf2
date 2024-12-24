/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2024/12/22 15:08:45 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/25 00:24:02 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Initialize printf structure members
 * @param p Pointer to printf structure
 */
void	init_printf(t_printf *p)
{
	p->buf_index = 0;
	p->total_len = 0;
}

/**
 * @brief Flush internal buffer to standard output
 * @param p Pointer to printf structure
 * @return 1 on success, -1 on error, 0 if buffer empty
 */
int	flush_buffer(t_printf *p)
{
	int	written;

	if (p->buf_index == 0)
		return (0);
	written = write(1, p->buffer, p->buf_index);
	if (written < 0)
		return (-1);
	p->total_len += written;
	p->buf_index = 0;
	return (1);
}

/**
 * @brief Add string to internal buffer with overflow handling
 * @param p Pointer to printf structure
 * @param str String to add
 * @param len Length of string
 * @return 1 on success, -1 on error
 */
int	add_to_buffer(t_printf *p, const char *str, int len)
{
	const char	*end;

	end = str + len;
	while (str < end)
	{
		if (p->buf_index == BUFSIZE)
		{
			if (flush_buffer(p) < 0)
				return (-1);
		}
		*(p->buffer + p->buf_index++) = *str++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_printf	p;
	const char	*ptr;
	int			ret;

	if (!format)
		return (-1);
	init_printf(&p);
	va_start(p.args, format);
	ptr = format;
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1))
		{
			if (x_formats(&p, *++ptr) < 0)
				return (-1);
		}
		else if (add_to_buffer(&p, ptr, 1) < 0)
			return (-1);
		ptr++;
	}
	va_end(p.args);
	ret = flush_buffer(&p);
	if (ret < 0)
		return (-1);
	return (p.total_len);
}
