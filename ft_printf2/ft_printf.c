
#include "ft_printf.h"

void	ft_parse_args(va_list args, const char *format, t_options *opts)
{
	size_t		index;

	index = -1;
	while (format[++index])
		if (format[index] != '%')
			ft_putchar(format[index], opts);
		else if (format[index] == '%' && format[index + 1])
		{
			ft_init_opts(opts);
			index += ft_parsing(args, format + index + 1, opts);
		}
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_options	opts;

	if (!format)
		return (-1);
	va_start(args, format);
	opts.symbols = 0;
	ft_parse_args(args, format, &opts);
	va_end(args);
	return (opts.error ? opts.symbols : -1);
}
