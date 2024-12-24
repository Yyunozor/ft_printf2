/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:15:54 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/24 23:38:24 by anpayot          ###   ########.fr       */
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
