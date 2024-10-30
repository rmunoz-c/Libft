/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:04:19 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024/10/30 17:16:03 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	char			*number;
	unsigned int	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = count_digits(n);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	number[len] = '\0';
	while (n > 0)
	{
		number[len - 1] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	return (number);
}
