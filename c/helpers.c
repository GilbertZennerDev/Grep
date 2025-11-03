/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:48:31 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/03 09:52:18 by gzenner          ###   ########.fr       */
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

void	closeonerror(int bytes_read)
{
	if (bytes_read > 0)
		return ;
	if (bytes_read < 0)
		perror("Input Reading Error");
	if (bytes_read == 0)
		perror("Input Empty Error");
	exit(1);
}

void	ft_print_substring(t_data *data)
{
	data->sub = ft_substr(data->buffer, data->start, data->i);
	printf("%s", data->sub);
	free(data->sub);
	if (data->filename)
		printf(": (%s)", data->filename);
	printf("\n");
}

void	ft_browse_stream(t_data *data)
{
	while (data->i && data->buffer[data->i - 1] != 10)
		--data->i;
	data->start = data->i;
	while (data->buffer[data->i] != 10 \
		&& data->i < ft_strlen(data->buffer))
		++data->i;
}
