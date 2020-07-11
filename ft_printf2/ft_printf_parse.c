
#include "ft_printf.h"

int		ft_accuracy(va_list args, char *format, t_options *opts)
{
	int		len;

	len = 1;
	if (format[len] != '*')
		while (ft_is_digit(format[len]))
		{
			opts->accuracy = opts->accuracy * 10 + format[len] - '0';
			len++;
		}
	else if (len++)
		opts->accuracy = va_arg(args, int);
	opts->is_acc = 1;
	return (len);
}

int		ft_width(va_list args, char *format, t_options *opts, int flag)
{
	int		len;

	len = 0;
	if (flag)
		opts->width = va_arg(args, int);
	else
		while (ft_is_digit(format[len]))
		{
			opts->width = opts->width * 10 + format[len] - '0';
			len++;
		}
	return (len);
}

void	ft_print_arg(va_list args, char *format, t_options *opts)
{
	if (opts->spec == 'c')
		ft_print_c((char)va_arg(args, int), opts);
	else if (ft_strchr("udi", opts->spec))
		ft_print_udi(args, format, opts);
	else if (opts->spec == 's')
		ft_print_s(va_arg(args, char *), opts);
}

int		ft_parsing(va_list args, const char *format, t_options *opts)
{
	int		index;
	int		nbr_len;

	index = 0;
	while (ft_is_flag(format[index]))
	{
		nbr_len = 1;
		if (format[index] == '0')
			opts->zero = 1;
		else if (format[index] == '*')
			ft_width(args, (char *)format + index, opts, 1);
		else if (format[index] == '.')
			nbr_len = ft_accuracy(args, (char *)format + index, opts);
		else if (format[index] == '-')
			opts->minus = 1;
		else if (ft_is_digit(format[index]))
			nbr_len = ft_width(args, (char *)format + index, opts, 0);
		index += nbr_len;
	}
	if ((opts->spec = (char)ft_is_spec(format[index++])))
		ft_print_arg(args, (char *)format + index, opts);
	return (index);
}
