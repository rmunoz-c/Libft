/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:04:23 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024/10/30 17:16:33 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_putui(unsigned int n);
int		ft_put_hex_ptr(unsigned long long int n, const char format, int is_ptr);
int		count_digits(unsigned int n);
char		*ft_utoa(unsigned int n);
int		ft_printf(char const *s, ...);
int		ft_conver(va_list args, const char format);

#endif