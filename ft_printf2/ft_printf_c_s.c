
#include "ft_printf.h"

char	*ft_str_width(char *str, t_options *opts)
{
	char	*new_str;

	if (opts->width < 0)
	{
		opts->minus = 1;
		opts->width *= -1;
	}
	if (opts->minus)
		new_str = ft_str_add_back(' ', str, opts->width - ft_strlen(str));
	else
		new_str = ft_str_add_front(' ', str, opts->width - ft_strlen(str));
	return (new_str);
}

char	*ft_str_accuracy(char *str, int accuracy)
{
	char	*new_str;

	if (!accuracy)
		new_str = ft_strdup("");
	else
	{
		new_str = (char *)malloc(sizeof(char) * (accuracy + 1));
		ft_strlcpy(new_str, str, accuracy + 1);
	}
	return (new_str);
}

void	ft_print_s(char *str, t_options *opts)
{
	char	*new_str;
	char	*tmp;

	if (!str)
		new_str = ft_strdup("(null)");
	else if (!*str)
		new_str = ft_strdup("");
	else
		new_str = ft_strdup(str);
	if (opts->is_acc && opts->accuracy >= 0 && opts->accuracy < ft_strlen(new_str))
	{
		tmp = new_str;
		new_str = ft_str_accuracy(new_str, opts->accuracy);
		free(tmp);
	}
	if (opts->width > ft_strlen(new_str) || ft_strlen(new_str) + opts->width < 0)
	{
		tmp = new_str;
		new_str = ft_str_width(new_str, opts);
		free(tmp);
	}
	ft_putstr(new_str, opts);
	free(new_str);
}

void	ft_print_c(char c, t_options *opts)
{
	if (opts->minus)
		ft_putchar(c, opts);
	if (opts->width--)
		while (opts->width--)
			ft_putchar(' ', opts);
	if (!(opts->minus))
		ft_putchar(c, opts);
}