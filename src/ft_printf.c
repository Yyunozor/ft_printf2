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

static void	init_printf(t_printf *p)
{
	p->len = 0;
}

int	ft_printf(const char *format, ...)
{
	t_printf	p;
	const char	*ptr;

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
		else
		{
			if (write(1, ptr, 1) < 0)
				return (-1);
			p.len++;
		}
		ptr++;
	}
	va_end(p.args);
	return (p.len);
}
