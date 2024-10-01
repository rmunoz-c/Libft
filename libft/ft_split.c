/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:13:33 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024/09/30 17:09:36 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_sub(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] != c && i > 0 && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_copy_sub(char const *start, size_t len)
{
	char	*str;
	size_t	count;

	if (!start)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	count = 0;
	while (count < len)
	{
		str[count] = start[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

static size_t	ft_len_sub(char const *s, size_t *i, char c )
{
	size_t	len;
	size_t	start;

	start = *i;
	while (s[*i] && s[*i] != c)
		i[0]++;
	len = *i - start;
	return (len);
}

static char	**ft_split_clean(char **array, size_t len)
{
	if (!array)
		return (NULL);
	while (len)
		free(array[--len]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**array;

	if (!s)
		return (NULL);
	array = ft_calloc(ft_count_sub(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			array[j++] = ft_copy_sub(&s[i], ft_len_sub(s, &i, c));
			if (!array[j - 1])
				return (ft_split_clean(array, j - 1));
		}
		else
			i++;
	}
	return (array);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str = "aholaaaaaaaaaaqueaaaaaaaaaaaaaaaaatalaaaaaaaaaa";
	char	c = 'a';
	char	**result;
	size_t	i = 0;

	result = ft_split(str, c);
	printf("Puntero result: %p\n", result);
	while (result[i])
	{
		printf("Res %lu: \"%s\", en dir: \"%p\"\n", i, result[i], result[i]);
		free(result[i]);
		i ++;
	}
	if (result)
	{
		printf("El cerrado está en dirección: \"%p\"\n", result[i]);
		free(result);
	}
	return (0);
}*/
