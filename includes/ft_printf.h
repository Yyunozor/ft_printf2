/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:08:45 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/24 23:40:32 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUFSIZE 128
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct s_printf
{
	va_list	args;
	char	buffer[BUFSIZE];
	int		buf_index;
	int		total_len;
	char	type;
}	t_printf;

/**
 * @brief Main printf implementation with buffered output
 * @param format Format string containing text and format specifiers
 * @param ... Variable arguments corresponding to format specifiers
 * @return Total number of characters printed or -1 on error
 */
int		ft_printf(const char *format, ...);

/* Buffer handling */
/**
 * @brief Initialize printf structure
 * @param p Pointer to printf structure
 */
void	init_printf(t_printf *p);

/**
 * @brief Flush the buffer to standard output
 * @param p Pointer to printf structure
 * @return 1 on success, -1 on error, 0 if buffer empty
 */
int		flush_buffer(t_printf *p);

/**
 * @brief Add string to buffer with overflow handling
 * @param p Pointer to printf structure
 * @param str String to add
 * @param len Length of string
 * @return 1 on success, -1 on error
 */
int		add_to_buffer(t_printf *p, const char *str, int len);

/* Format handling */
/**
 * @brief Handle format specifier routing
 * @param p Pointer to printf structure
 * @param type Format specifier character
 * @return Result of format handler or -1 on error
 */
int		x_format(t_printf *p, char type);

/**
 * @brief Handle numeric format specifiers
 * @param p Pointer to printf structure
 * @param type Format specifier character
 * @return Result of number conversion or -1 on error
 */
int		x_numbers(t_printf *p, char type);

/**
 * @brief Convert number to string in given base
 * @param n Number to convert
 * @param base Base string containing characters
 * @param blen Length of base
 * @param p Pointer to printf structure
 * @return Result of buffer addition or -1 on error
 */
int		convert_nb(unsigned long n, const char *base, int blen, t_printf *p);

#endif