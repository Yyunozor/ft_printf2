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
 * @brief Initializes the printf structure
 * @param p Pointer to the t_printf structure to initialize
 */
static void	init_printf(t_printf *p)
{
	p->len = 0;
}

/**
 * @brief Custom implementation of printf function
 * @param format Format string containing the text and format specifiers
 * @param ... Variable arguments corresponding to the format specifiers
 * @return Total number of characters printed, or -1 on error
 */
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
