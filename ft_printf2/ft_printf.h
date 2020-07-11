
#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_options
{
	int		symbols;
	char	spec;
	int		width;
	int		accuracy;
	int		is_acc;
	char	zero;
	char	minus;
	int		error;
}					t_options;

/* ft_printf */
int					ft_printf(const char *format, ...);
void				ft_parse_args(va_list args, const char *format,
									t_options *opts);

/* ft_printf_utils */
void				ft_init_opts(t_options *opts);
int					ft_is_flag(char c);
int					ft_is_spec(char c);
char				*ft_str_add_front(char c, char *str, size_t count);
char				*ft_str_add_back(char c, char *str, size_t count);

/* ft_printf_parse */
int					ft_parsing(va_list args, const char *format,
								t_options *opts);
void				ft_print_arg(va_list args, char *format, t_options *opts);
int					ft_width(va_list args, char *format, t_options *opts,
								int flag);
int					ft_accuracy(va_list args, char *format, t_options *opts);

/* ft_printf_libft */
void				ft_putchar(char c, t_options *opts);
int					ft_is_digit(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_llitoa_base(long long nbr, char type, int base);
void				ft_putstr(char *str, t_options *opts);

/* ft_printf_libft_add */
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/* ft_printf_c_s */
void				ft_print_c(char c, t_options *opts);
void				ft_print_s(char *str, t_options *opts);
char				*ft_str_accuracy(char *str, int accuracy);
char				*ft_str_width(char *str, t_options *opts);

/* ft_printf_u_d_i */
void				ft_print_udi(va_list args, char *format, t_options *opts);
char				*ft_uid_width_handle(char *str, t_options *opts);

#endif
