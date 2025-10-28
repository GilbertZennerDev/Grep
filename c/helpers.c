/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:48:31 by gzenner           #+#    #+#             */
/*   Updated: 2025/10/28 09:17:36 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftif.h"

void	minicalloc_char(char buffer[])
{
	unsigned int	i;

	i = 0;
	while (i < 1024)
		buffer[i++] = 0;
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
