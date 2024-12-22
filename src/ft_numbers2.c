/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:58:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 17:59:17 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	x_uint(t_format *fmt)
{
	unsigned int	n;

	n = va_arg(fmt->args, unsigned int);
	return (ft_putunbr_base(n, "0123456789", 10, &fmt->len));
}

int	x_hex(t_format *fmt, const char *base)
{
	unsigned int	n;

	n = va_arg(fmt->args, unsigned int);
	return (ft_putunbr_base(n, base, 16, &fmt->len));
}
