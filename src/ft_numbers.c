/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2024/12/22 15:08:34 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/27 14:09:13 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	x_nbr(unsigned long n, const char *base, int blen)
{
	char			buf[21];
	char			*ptr;
	int				len;
	unsigned long	num;

	ptr = buf + sizeof(buf) - 1;
	*ptr = '\0';
	num = n;
	if (num == 0)
	{
		*--ptr = base[0];
	}
	else
	{
		while (num)
		{
			*--ptr = base[num % blen];
			num /= blen;
		}
	}
	len = ft_strlen(ptr);
	if (write(1, ptr, len) < 0)
		return (-1);
	return (len);
}

static int	x_int(t_printf *p)
{
	long	num;
	int		len;

	num = va_arg(p->args, int);
	if (num < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		p->len++;
		num = -num;
	}
	len = x_nbr(num, "0123456789", 10);
	if (len < 0)
		return (-1);
	p->len += len;
	return (1);
}

static int	x_hex(t_printf *p, char type)
{
	int			len;
	const char	*hex_base;

	if (type == 'x')
		hex_base = HEX_LOWER;
	else
		hex_base = HEX_UPPER;
	len = x_nbr(va_arg(p->args, unsigned int), hex_base, 16);
	if (len < 0)
		return (-1);
	p->len += len;
	return (1);
}

int	x_numbers(t_printf *p, char type)
{
	int	len;

	if (type == 'd' || type == 'i')
		return (x_int(p));
	if (type == 'u')
	{
		len = x_nbr(va_arg(p->args, unsigned int), "0123456789", 10);
		if (len < 0)
			return (-1);
		p->len += len;
		return (1);
	}
	if (type == 'x' || type == 'X')
		return (x_hex(p, type));
	return (-1);
}
