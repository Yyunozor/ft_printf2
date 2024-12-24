/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:45 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/24 23:40:55 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_printf(t_printf *p)
{
	p->buf_index = 0;
	p->total_len = 0;
}

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

int	add_to_buffer(t_printf *p, const char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (p->buf_index == BUFSIZE)
		{
			if (flush_buffer(p) < 0)
				return (-1);
		}
		p->buffer[p->buf_index++] = str[i++];
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_printf	p;
	int			i;
	int			ret;

	if (!format)
		return (-1);
	init_printf(&p);
	va_start(p.args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (x_format(&p, format[++i]) < 0)
				return (-1);
		}
		else if (add_to_buffer(&p, &format[i], 1) < 0)
			return (-1);
		i++;
	}
	va_end(p.args);
	ret = flush_buffer(&p);
	if (ret < 0)
		return (-1);
	return (p.total_len);
}
