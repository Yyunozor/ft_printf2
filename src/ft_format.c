/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:34 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 17:43:37 by anpayot          ###   ########.fr       */
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
	int		written;

	c = va_arg(fmt->args, int);
	written = write(1, &c, 1);
	if (written == -1)
		return (-1);
	fmt->len += written;
	return (1);
}

/**
 * @brief Handles string format specifier (%s) with optimized pointer arithmetic
 * @param fmt Pointer to format structure containing args and state
 * @return 1 on success
 */
int	x_str(t_format *fmt)
{
	const char	*str;
	int			written;

	str = va_arg(fmt->args, char *);
	if (!str)
		str = "(null)";
	written = write(1, str, ft_strlen(str));
	if (written == -1)
		return (-1);
	fmt->len += written;
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
	int				written;

	ptr = (unsigned long)va_arg(fmt->args, void *);
	if (ptr == 0)
	{
		written = write(1, "0x0", 3);
		if (written == -1)
			return (-1);
		fmt->len += written;
		return (1);
	}
	written = write(1, "0x", 2);
	if (written == -1)
		return (-1);
	fmt->len += written;
	return (ft_putunbr_base(ptr, HEX_LOWER, 16, &fmt->len));
}

/**
 * @brief Handles percent format specifier (%%)
 * @return 1 on success
 */
int	x_percent(void)
{
	int	written;

	written = write(1, "%", 1);
	if (written == -1)
		return (-1);
	return (1);
}
