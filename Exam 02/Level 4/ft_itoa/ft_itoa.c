#include <unistd.h>

static int	ft_count(long int i)
{
	int	count;

	count = 0;
	if (i <= 0)
		count++;
	while (i != 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	i = ft_count(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

/*int	main(void)
{
	char	*result;

	result = ft_itoa(-123);
	printf("El resultado es: %s\n", result);
	free (result);
	return (0);
}*/
