/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:16 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/03 11:22:00 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grep.h"

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

void	browsembuffer(t_data *data)
{
	int		nl;
	char	*line;
	char	*tmpbuffer;

	nl = strchr(data->mbuffer, '\n') - &data->mbuffer[0];
	while (nl >= 0)
	{
		line = ft_substr(data->mbuffer, 0, nl);
		tmpbuffer = data->mbuffer;
		data->mbuffer = ft_substr(data->mbuffer, nl + 1);
		free(tmpbuffer);
		if (strstr(line, data->target) != NULL)
			printf("%s\n", line);
		free(line);
		nl = strchr(data->mbuffer, '\n') - &data->mbuffer[0];
	}
	if (strstr(data->mbuffer, data->target) != NULL)
		printf("%s\n", line);
}

void	ftif_filename(const char *filename, const char *target)
{
	t_data	data;
	int		bytes_read;

	minicalloc_char(data.buffer);
	data.target = strdup(target);
	data.fd = open(filename, O_RDONLY);
	data.filename = strdup(filename);
	bytes_read = read(data.fd, data.buffer, READ_SIZE);
	closeonerror(bytes_read);
	data.mbuffer = strdup(data.buffer);
	browsembuffer(&data);
	free(data.mbuffer);
	free(data.filename);
	free(data.target);
	close(data.fd);
}

void	ftif(const char *target)
{
	t_data	data;
	int		bytes_read;

	data.fd = 0;
	data.target = strdup(target);
	data.filename = NULL;
	minicalloc_char(data.buffer);
	bytes_read = read(data.fd, data.buffer, READ_SIZE);
	closeonerror(bytes_read);
	data.mbuffer = strdup(data.buffer);
	browsembuffer(&data);
	free(data.mbuffer);
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
