/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:22:16 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024/09/30 15:44:41 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (!(size == 0 && nmemb > SIZE_MAX / size))
	{
		array = (void *) malloc(size * nmemb);
		if (!array)
			return (NULL);
		return (ft_memset(array, 0, size * nmemb));
	}
	return (NULL);
}

/*int	main(void)
{
	size_t	n = 5;
	size_t	size = sizeof(int);

	int *array = (int *)ft_calloc(n, size);
	if (!array)
	{
		printf("No se pudo asignar la memoria\n");
		return (1);
	}

	size_t	count = 0;
	while (count < n)
	{
		printf("array[%zu] = %d\n", count, array[count]);
		count++;
	}
	
	free(array);
	return (0);
}*/
