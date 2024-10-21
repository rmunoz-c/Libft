/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:19:28 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024/10/21 13:50:17 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if ((char)c == '\0')
		return ((char *)&s[count]);
	return (NULL);
}
size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = (char *) malloc((len + 1) * sizeof(char));
	count = 0;
	if (!str)
		return (NULL);
	while (count < len)
	{
		str[count] = s[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	size_t	i;

	len = ft_strlen(s) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}