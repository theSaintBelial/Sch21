
#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t		str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}

char		*ft_strdup(const char *str)
{
	char			*cpy;
	size_t			len;

	len = ft_strlen(str);
	if (!(cpy = (char *)malloc(len + 1)))
		return (NULL);
	cpy[len] = '\0';
	while (len--)
		cpy[len] = str[len];
	return (cpy);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = -1;
	if (!dst || !src)
		return (0);
	if (size)
	{
		while (src[++i] && i < size - 1)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
