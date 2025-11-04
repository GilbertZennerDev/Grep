/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:16 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/04 16:20:40 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grep.hpp"

/*
new start:
strdup the buffer.
then  use strchr to find the first newline
then substr only that substring. Check for target.
Then strdup the buffer without that substring, free the old str.
Continue until buffer empty.

more planning

browsembuffer(data)
takes the entire malloced buffer
loop:
searched for newline:
if none found:
it gives the pointer of the entire mbufffer to line
else:
it cuts the first line out of the mbuffer
stores that snippet in line
and gives mbuffer the rest as substring 

now we got the line:
now we just run a function which checks whether the word is in the string.
there is a function in libft for that
search needle in haystack (strstr)

then it checks whether the searched word is in that line

what is the name of my searched stuff
*/

Grep::Grep(){}
Grep::~Grep(){}

void	Grep::browsembuffer(t_data *data)
{
	int		nl;
	char	*tmpbuffer;
	char	*line;

	nl = ft_strchr(data->mbuffer, '\n') - &data->mbuffer[0];
	while (nl >= 0)
	{
		line = ft_substr(data->mbuffer, 0, nl);
		tmpbuffer = data->mbuffer;
		data->mbuffer = ft_substr(data->mbuffer, nl + 1 \
			, ft_strlen(data->mbuffer));
		free(tmpbuffer);
		if (ft_strstr(line, data->target) != -1)
			printf("%s\n", line);
		free(line);
		nl = ft_strchr(data->mbuffer, '\n') - &data->mbuffer[0];
	}
	if (nl < 0)
	{
		line = data->mbuffer;
		if (ft_strstr(line, data->target) != -1)
			printf("%s\n", line);
	}
}

void	Grep::grep_filename(const char *filename, const char *target)
{
	t_data	data;
	int		bytes_read;

	minicalloc_char(data.buffer);
	data.target = ft_strdup(target);
	data.fd = open(filename, O_RDONLY);
	data.filename = ft_strdup(filename);
	bytes_read = read(data.fd, data.buffer, 1024 * 1024);
	printf("bytes read: %d\n", bytes_read);
	closeonerror(bytes_read);
	data.mbuffer = ft_strdup(data.buffer);
	browsembuffer(&data);
	free(data.mbuffer);
	free(data.filename);
	free(data.target);
	close(data.fd);
}

void	Grep::grep(const char *target)
{
	t_data	data;
	int		bytes_read;

	data.fd = 0;
	data.target = ft_strdup(target);
	data.filename = NULL;
	minicalloc_char(data.buffer);
	bytes_read = read(data.fd, data.buffer, 1024 * 1024);
	closeonerror(bytes_read);
	data.mbuffer = ft_strdup(data.buffer);
	browsembuffer(&data);
	free(data.mbuffer);
	free(data.target);
	close(data.fd);
}

int	main(int ac, char **av)
{
    Grep grep = Grep();
	if (ac == 2)
		grep.grep(av[1]);
	if (ac == 3)
		grep.grep_filename(av[1], av[2]);
	return (0);
}
