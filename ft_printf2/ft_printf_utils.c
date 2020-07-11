
#include "ft_printf.h"

void	ft_init_opts(t_options *opts)
{
	opts->spec = 0;
	opts->width = 0;
	opts->accuracy = 0;
	opts->is_acc = 0;
	opts->minus = 0;
	opts->zero = 0;
	opts->error = 0;
}

int		ft_is_spec(char c)
{
	if (ft_strchr("csdpiuxX%", c))
		return (c);
	return (0);
}

int		ft_is_flag(char c)
{
	if (ft_is_digit(c) || ft_strchr("-0.*", c))
		return (c);
	return (0);
}

char	*ft_str_add_front(char c, char *str, size_t count)
{
	char	*new_str;
	size_t	index;

	if (!(new_str = (char *)malloc(sizeof(char) *
			(count + ft_strlen(str) + 1))))
		return (NULL);
	index = 0;
	if (*str == '-' && c != ' ')
	{
		new_str[index++] = '-';
		str++;
	}
	while (count--)
		new_str[index++] = c;
	while (*str)
		new_str[index++] = *str++;
	new_str[index] = 0;
	return (new_str);
}

char	*ft_str_add_back(char c, char *str, size_t count)
{
	char	*new_str;
	size_t	index;

	if (!(new_str = (char *)malloc(sizeof(char) *
			(count + ft_strlen(str) + 1))))
		return (NULL);
	index = 0;
	while (*str)
		new_str[index++] = *str++;
	while (count--)
		new_str[index++] = c;
	new_str[index] = 0;
	return (new_str);
}
