
#include "ft_printf.h"

char	*ft_uid_width_handle(char *str, t_options *opts)
{
	char	*new_str;
	char	symbol;

	symbol = '0';
	if (!opts->zero || (opts->zero && opts->width < 0)
			|| (opts->zero && opts->width && opts->accuracy >= 0))
		symbol = ' ';
	if (opts->width < 0)
	{
		opts->minus = 1;
		opts->width *= -1;
	}
	if (!opts->minus)
		new_str = ft_str_add_front(symbol, str, (opts->width - ft_strlen(str)));
	else if (opts->minus && opts->width > ft_strlen(str))
		new_str = ft_str_add_back(symbol, str, (opts->width - ft_strlen(str)));
	else
		new_str = ft_strdup(str);
	return (new_str);
}

void	ft_print_udi(va_list args, char *format, t_options *opts)
{
	long	number;
	char	*str;
	char	*tmp;

	if (opts->spec == 'u')
		number = va_arg(args, unsigned int);
	else
		number = va_arg(args, int);
	str = ft_llitoa_base(number, 0, 10);
	if (opts->is_acc && opts->accuracy > (ft_strlen(str) - (number < 0 ? 1 : 0)))
	{
		tmp = str;
		str = ft_str_add_front('0', str,
				opts->accuracy - ft_strlen(str) + (number < 0 ? 1 : 0));
		free(tmp);
	}
	if (opts->width > ft_strlen(str) || opts->width < 0)
	{
		tmp = str;
		str = ft_uid_width_handle(str, opts);
		free(tmp);
	}
	ft_putstr(str, opts);
	free(str);
}
