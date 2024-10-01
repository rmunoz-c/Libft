/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:50:08 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024/09/30 15:44:41 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	if (c == '\0')
		return ((char *)&s[count]);
	return (0);
}

/*int	main(void)
{
	char str[] = "Hola que tal?";
	char *result;

	result = ft_strchr(str, 'q');

	if (result)
		write(1, result, ft_strlen(result));
	else
		write(1, "No encontrado", 14);
	return (0);
}*/
