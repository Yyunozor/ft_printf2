/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:07:39 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/28 13:14:20 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/**
 * @brief Handles the character format specifier ('c')
 * @param p Pointer to the printf structure
 * @return 1 on success, -1 on error
 */
static int	x_char(t_printf *p)
{
	char	c;

	c = va_arg(p->args, int);
	if (write(1, &c, 1) < 0)
		return (-1);
	p->len++;
	return (1);
}

/**
 * @brief Handles the string format specifier ('s')
 * @param p Pointer to the printf structure
 * @return 1 on success, -1 on error
 */
static int	x_str(t_printf *p)
{
	const char	*str;
	int			len;

	str = va_arg(p->args, const char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (write(1, str, len) < 0)
		return (-1);
	p->len += len;
	return (1);
}

/**
 * @brief Handles the pointer format specifier ('p')
 * @param p Pointer to the printf structure
 * @return 1 on success, -1 on error
 */
static int	x_ptr(t_printf *p)
{
	unsigned long	ptr;
	int				len;

	ptr = (unsigned long)va_arg(p->args, void *);
	if (write(1, "0x", 2) < 0)
		return (-1);
	p->len += 2;
	if (!ptr)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		p->len++;
		return (1);
	}
	len = x_nbr_base(ptr, HEX_LOWER, 16);
	if (len < 0)
		return (-1);
	p->len += len;
	return (1);
}

/**
 * @brief Routes format specifiers to their respective handling functions
 * @param p Pointer to the printf structure
 * @param type The format specifier character
 * @return 1 on success, -1 on error
 */
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
	{
		if (write(1, "%", 1) < 0)
			return (-1);
		p->len++;
		return (1);
	}
	return (ft_print_numbers(p, type));
}
