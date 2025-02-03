#include <stdio.h>

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int get_digit(char c, int digits_in_base)
{
	int max_digit;

	if (digits_in_base <= 10)
		max_digit = digits_in_base - 1 + '0';
	else
		max_digit = digits_in_base - 10 - 1 + 'a';

	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0; // Acumula el número convertido.
	int sign = 1;
	int digit; // Almacena el valor numérico del carácter actual.

	if (str == NULL || str_base < 2 || str_base > 16)
		return 0;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while (*str)
	{
		digit = get_digit(to_lower(*str), str_base);
		if (digit == -1)
			break;
		result = result * str_base + digit;
		++str;
	}
	return (result * sign);
}

int main() {
    char *test_cases[] = {
        "1010",      // Binario (base 2)
        "-1010",     // Binario negativo
        "123",       // Decimal (base 10)
        "-123",      // Decimal negativo
        "7A",        // Hexadecimal (base 16, letras mayúsculas)
        "7d",        // Hexadecimal (base 16, letras minúsculas)
        "1A3",       // Base 16, mezcla de letras y números
        "-1A3",      // Base 16 negativo
        "777",       // Octal (base 8)
        "2A",        // Base 11
        "ZZ",        // Base 36 (solo conceptual, fuera del rango permitido)
        NULL         // Finalizador
    };

    int bases[] = {2, 2, 10, 10, 12, 14, 16, 16, 8, 11, 36};
    int num_tests = sizeof(bases) / sizeof(bases[0]);

    printf("Testing ft_atoi_base:\n");
    for (int i = 0; i < num_tests; ++i) {
        char *test_case = test_cases[i];
        int base = bases[i];
        if (test_case != NULL) {
            int result = ft_atoi_base(test_case, base);
            printf("Input: \"%s\" in base %d -> Result: %d\n", test_case, base, result);
        }
    }

    return 0;
}