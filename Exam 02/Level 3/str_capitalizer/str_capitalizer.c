/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 15:49:27 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024-11-25 15:49:27 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ste(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z' && !ste(str[i - 1]))
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z' && ste(str[i - 1]))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		write(1, "\n", 1);
	i = 1;
	while (i < argc)
	{
		str_capitalizer(argv[i]);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
