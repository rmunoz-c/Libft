/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 15:08:09 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024-11-25 15:08:09 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	fizzbuzz(void)
{
	int n;

	n = 1;
	while (n <= 100)
	{
		if (!(n % 3 == 0 || n % 5 == 0))
			ft_putnbr(n);
		else if (n % 3 == 0 && n % 5 != 0)
			write(1, "fizz", 4);
		else if (n % 3 != 0 && n % 5 == 0)
			write(1, "buzz", 4);
		else if (n % 3 == 0 || n % 5 == 0)
			write(1, "fizzbuzz", 8);
		write (1, "\n", 1);
		n++;
	}
}

int main()
{
	fizzbuzz();
	return(0);
}