/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:08:53 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/22 17:59:17 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_write_str(const char *str, int *len)
{
	int	written;

	written = write(1, str, ft_strlen(str));
	if (written == -1)
		return (-1);
	*len += written;
	return (1);
}

int	ft_putunbr_base(unsigned long n, const char *base, int blen, int *len)
{
	char	buf[21];
	char	*ptr;

	ptr = buf + 20;
	*ptr = '\0';
	if (n == 0)
		*--ptr = base[0];
	while (n > 0)
	{
		*--ptr = base[n % blen];
		n /= blen;
	}
	return (handle_write_str(ptr, len));
}

/**
 * @brief Optimized integer handler with direct buffer manipulation
 * @param fmt Pointer to format structure containing args and state
 * @return 1 on success
 */
int	x_int(t_format *fmt)
{
	char	buf[12];
	char	*ptr;
	long	num;
	int		n;

	n = va_arg(fmt->args, int);
	num = n;
	ptr = buf + 11;
	*ptr = '\0';
	if (n < 0)
		num = -num;
	if (num == 0)
		*--ptr = '0';
	while (num > 0)
	{
		*--ptr = '0' + (num % 10);
		num /= 10;
	}
	if (n < 0)
		*--ptr = '-';
	return (handle_write_str(ptr, &fmt->len));
}
