#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*duped;
	int	i;

	duped = NULL;
	len = ft_strlen(s);
	duped = (char *)malloc(len + 1);
	if (!duped)
		return (NULL);
	i = 0;
	while (s[i])
	{
		duped[i] = s[i];
		i++;
	}
	duped[i] = '\0';
	return (duped);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t			i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	char	to_find;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	to_find = (char)c;
	while(*ptr)
	{
		if (*ptr == to_find)
			return (ptr);
		ptr++;
	}
	if (to_find == '\0')
		return (ptr);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*re;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	re = (char *)malloc(s1_len + s2_len + 1);
	if (!re)
		return (NULL);
	ft_memcpy(re, s1, s1_len);
	ft_memcpy(re + s1_len, s2, s2_len);
	re[s1_len + s2_len] = '\0';
	return (re);
}
