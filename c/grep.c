/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:16 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/03 09:54:35 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grep.h"

/*
new start:
strdup the buffer.
then  use strchr to find the first newline
then substr only that substring. Check for target.
Then strdup the buffer without that substring, free the old str.
Continue until buffer empty.
*/

/*void	browsembuffer(t_data *data)
{
	int		nl;
	int		len;
	char	*tmpbuffer;
	char	*line;

	nl = ft_strchr(data->mbuffer, '\n') - &data->mbuffer[0];
	printf("nl: %d\n", nl);
	if (nl == -1)
	{
		line = data->mbuffer;
	}
	else
	{
		line = ft_substr(data->mbuffer, 0, nl);
		tmpbuffer = data->mbuffer;
		len = strlen(data->mbuffer);
		data->mbuffer = ft_substr(data->mbuffer, nl, len);
		*ft_strnstr(data->mbuffer, )
		free(tmpbuffer);
	}
}*/

void	findtargetinbuffer(t_data *data)
{
	data->i = 0;
	data->line_index = 1;
	while (data->buffer[data->i])
	{
		data->j = 0;
		if (data->buffer[data->i] == '\n')
			++data->line_index;
		while (data->buffer[data->i] == data->target[data->j])
		{
			++data->i;
			++data->j;
		}
		if (data->target[data->j] == '\0')
		{
			ft_browse_stream(data);
			ft_print_substring(data);
		}
		++data->i;
	}
}

void	ftif_filename(const char *filename, const char *target)
{
	t_data	data;
	int		bytes_read;

	minicalloc_char(data.buffer);
	data.target = ft_strdup(target);
	data.fd = open(filename, O_RDONLY);
	data.filename = ft_strdup(filename);
	bytes_read = read(data.fd, data.buffer, 1024);
	closeonerror(bytes_read);
	data.mbuffer = ft_strdup(data.buffer);
	findtargetinbuffer(&data);
	free(data.filename);
	free(data.target);
	close(data.fd);
}

void	ftif(const char *target)
{
	t_data	data;
	int		bytes_read;

	data.fd = 0;
	data.target = ft_strdup(target);
	data.filename = NULL;
	minicalloc_char(data.buffer);
	bytes_read = read(data.fd, data.buffer, 1024);
	closeonerror(bytes_read);
	data.mbuffer = ft_strdup(data.buffer);
	findtargetinbuffer(&data);
	free(data.target);
	close(data.fd);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ftif(av[1]);
	if (ac == 3)
		ftif_filename(av[1], av[2]);
	return (0);
}
