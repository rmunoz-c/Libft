/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:22:35 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024/10/30 21:01:13 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putstr(char *s)
{
	if (s)
		write (1, s, ft_strlen(s));
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (ft_strlen(s));
}

int	ft_putnbr(int n)
{
	int		len;
	char	*number;

	number = ft_itoa(n);
	if (!number)
		return (0);
	len = ft_putstr(number);
	free(number);
	return (len);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putui(unsigned int n)
{
	int		len;
	char	*number;

	len = 0;
	if (n == 0)
		len += write (1, "0", 1);
	else
	{
		number = ft_utoa(n);
		if (number)
		{
			len += ft_putstr(number);
			free(number);
		}
	}
	return (len);
}

int	ft_put_hex_ptr(unsigned long long int n, const char format, int is_ptr)
{
	int	printed_chars;

	printed_chars = 0;
	if (is_ptr)
		printed_chars += write(1, "0x", 2);
	if (n == 0)
		return (printed_chars + write(1, "0", 1));
	if (n >= 16)
		printed_chars += ft_put_hex_ptr(n / 16, format, 0);
	if (n % 16 <= 9)
		printed_chars += ft_putchar((n % 16 + '0'));
	else if (format == 'x' || is_ptr)
			printed_chars += ft_putchar((n % 16 - 10 + 'a'));
	else if (format == 'X')
			printed_chars += ft_putchar((n % 16 - 10 + 'A'));
	return (printed_chars);
}
