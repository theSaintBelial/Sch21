
#include "ft_printf.h"

void	ft_putchar(char c, t_options *opts)
{
	write(1, &c, 1);
	opts->symbols++;
}

int		ft_is_digit(int c)
{
	return (c >= '0' && c <= '9') ? c : 0;
}

char	*ft_strchr(const char *str, int c)
{
	size_t		i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return ((char *)str + i);
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_llitoa_base(long long nbr, char type, int base)
{
	int			i;
	long long	tmp;
	char		*str;
	char		letter;
	int			sign;

	tmp = (nbr < 0) ? -nbr : nbr;
	sign = (nbr < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	letter = (type) ? 'A' : 'a';
	while ((tmp /= base) > 0)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	tmp = (nbr < 0) ? -(long)nbr : nbr;
	while (i-- + sign)
	{
		str[i] = (tmp % base >= 10)
				? tmp % base + letter - 10 : tmp % base + '0';
		tmp /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}

void	ft_putstr(char *str, t_options *opts)
{
	while (*str)
		ft_putchar(*str++, opts);
}
