/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:07:39 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/25 00:08:03 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/**
 * @brief Handle character format specifier (%c)
 * @param p Pointer to printf structure
 * @return Result of buffer addition or -1 on error
 */
static int	x_char(t_printf *p)
{
	char	c;

	c = va_arg(p->args, int);
	return (add_to_buffer(p, &c, 1));
}

/**
 * @brief Handle string format specifier (%s)
 * @param p Pointer to printf structure
 * @return Result of buffer addition or -1 on error
 */
static int	x_str(t_printf *p)
{
	const char	*str;

	str = va_arg(p->args, const char *);
	if (!str)
		str = "(null)";
	return (add_to_buffer(p, str, ft_strlen(str)));
}

/**
 * @brief Handle pointer format specifier (%p)
 * @param p Pointer to printf structure
 * @return Result of buffer addition or -1 on error
 */
static int	x_ptr(t_printf *p)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(p->args, void *);
	if (!ptr)
		return (add_to_buffer(p, "0x0", 3));
	if (add_to_buffer(p, "0x", 2) < 0)
		return (-1);
	return (x_nbr(ptr, HEX_LOWER, 16, p));
}

int	x_formats(t_printf *p, char type)
{
	p->type = type;
	if (type == 'c')
		return (x_char(p));
	if (type == 's')
		return (x_str(p));
	if (type == 'p')
		return (x_ptr(p));
	if (type == '%')
		return (add_to_buffer(p, "%", 1));
	return (x_numbers(p, type));
}
