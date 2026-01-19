/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:20:12 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/04 16:12:19 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grep.h"

void	minicalloc_char(char buffer[])
{
	unsigned int	i;

	i = 0;
	while (i < 1024)
		buffer[i++] = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	if (len + 1 == 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
	{
		sub = (char *)malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (s_len - start < len)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

int	ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
			k = i;
		while (haystack[i] == needle[j])
		{
			++i;
			++j;
		}
		if (needle[j] == 0)
			return (k);
		++i;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
