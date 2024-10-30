/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:50:19 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024/10/30 17:12:20 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conver(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_put_hex_ptr(va_arg(args, unsigned long long), 'x', 1);
	else if (format == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putui(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_put_hex_ptr(va_arg(args, unsigned long long), 'x', 0);
	else if (format == 'X')
		len += ft_put_hex_ptr(va_arg(args, unsigned long long), 'X', 0);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_conver(args, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*int main()
{
	int print_return;
	
	print_return = ft_printf("Esto es un caracter: %c\n", 'W');
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	print_return = ft_printf("Esto es un string: %s\n", "Hola que tal?");
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	print_return = ft_printf("Esto es un string NULL: %s\n", (char *)NULL);
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	print_return = ft_printf("Esto es un entero negativo: %d\n", -42);
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	print_return = ft_printf("Esto es un unsigned int: %u\n", 42);
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	print_return = ft_printf("Esto es un hexadecimal en minusculas: %x\n", 255);
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	print_return = ft_printf("Esto es un hexadecimal en mayusculas: %X\n", 255);
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	int	n = 42;
	print_return = ft_printf("Esto es un puntero: %p\n", &n);
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	print_return = ft_printf("Esto es un porcentaje: %%\n");
	ft_printf("El retorno de ft_printf es: %d\n", print_return);

	return (0);
}*/