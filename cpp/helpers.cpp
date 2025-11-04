/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:20:12 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/04 16:19:45 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grep.hpp"

void	Grep::closeonerror(int bytes_read)
{
	if (bytes_read > 0)
		return ;
	if (bytes_read < 0)
		perror("Input Reading Error");
	if (bytes_read == 0)
		perror("Input Empty Error");
	exit(1);
}

void	Grep::minicalloc_char(char buffer[])
{
	unsigned int	i;

	i = 0;
	while (i < 1024)
		buffer[i++] = 0;
}

size_t	Grep::ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*Grep::ft_substr(char const *s, unsigned int start, size_t len)
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

int	Grep::ft_strstr(char *haystack, char *needle)
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
