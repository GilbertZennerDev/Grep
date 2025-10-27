/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ftif.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pinkwish <pinkwish@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/07/25 22:35:03 by pinkwish		  #+#	#+#			 */
/*   Updated: 2025/07/25 23:22:02 by pinkwish		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

/*let me shorten this code
the main idea is that I just print the found lines 
directly to the screen instead of storing them
this way I can spare the storing and the callocing
*/

#include "ftif.h"

void	minicalloc_char(char buffer[])
{
	unsigned int	i;

	i = 0;
	while (i < 1024)
		buffer[i++] = 0;
}

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
			while (data->i && data->buffer[data->i - 1] != 10)
				--data->i;
			while (data->buffer[data->i] != 10 \
				&& data->i < ft_strlen(data->buffer))
				printf("%c", data->buffer[data->i++]);
			if (data->filename)
				printf(": (%s)", data->filename);
			printf("\n");
		}
		++data->i;
	}
}

// for reading from a file.
void	ftif_filename(const char *filename, const char *target)
{
	t_data	data;
	int		bytes_read;

	minicalloc_char(data.buffer);
	data.target = ft_strdup(target);
	data.fd = open(filename, O_RDONLY);
	data.filename = ft_strdup(filename);
	bytes_read = read(data.fd, data.buffer, 1023);
	findtargetinbuffer(&data);
	free(data.filename);
	free(data.target);
	close(data.fd);
}

//for reading directly from stdin / pipe
void	ftif(const char *target)
{
	t_data	data;
	int		bytes_read;

	data.fd = 0;
	data.target = ft_strdup(target);
	data.filename = NULL;
	minicalloc_char(data.buffer);
	bytes_read = read(data.fd, data.buffer, 1023);
	if (bytes_read < 0)
	{
		perror("Input Reading Error");
		exit(1);
	}
	if (bytes_read == 0)
	{
		perror("Input Empty Error");
		exit(1);
	}
	findtargetinbuffer(&data);
	close(data.fd);
}

int	main(int ac, char **av)
{
	t_data	data;

	minicalloc_char(data.buffer);
	if (ac == 2)
		ftif(av[1]);
	if (ac == 3)
		ftif_filename(av[1], av[2]);
	return (0);
}
