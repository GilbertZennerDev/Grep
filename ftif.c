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

#include "ftif.h"

void	minicalloc_char(char buffer[])
{
	unsigned int i;

	i = 0;
	while (i < 1024)
		buffer[i++] = 0;
}

void	findtargetinbuffer(t_data *data)
{
	data->line_index = 1;
	data->i = 0;
	while(data->buffer[data->i])
	{
		data->j = 0;
		if (data->buffer[data->i] == '\n')
			++data->line_index;
		while(data->buffer[data->i] == data->target[data->j])
		{
			++data->i;
			++data->j;
		}
		if (data->target[data->j] == '\0')
		{
			while(data->i && data->buffer[data->i-1] != 10)
				--data->i;
			while(data->buffer[data->i] != 10 && data->i < ft_strlen(data->buffer))
				printf("%c", data->buffer[data->i++]);
			if (data->filename)
				printf(": (%s)", data->filename);
			printf("\n");
		}
		++data->i;
	}
}

void ftif_filename(const char *filename, const char *target)
{
	t_data	data;

	data.filename = ft_strdup(filename);
	data.target = ft_strdup(target);
	data.fd = open(filename, O_RDONLY);
	minicalloc_char(data.buffer);
	data.bytes_read = read(data.fd, data.buffer, 1023);
	findtargetinbuffer(&data);
	free(data.filename);
	free(data.target);
	close(data.fd);
}

void ftif(const char *target)
{
	t_data data;	

	data.fd = 0;
	data.target = ft_strdup(target);
	data.filename = NULL;
	minicalloc_char(data.buffer);
	data.bytes_read = read(data.fd, data.buffer, 1023);
	if (data.bytes_read < 0)
		perror("Input Reading Error");
	if (data.bytes_read == 0)
		perror("Input Empty Error");
	findtargetinbuffer(&data);
	close(data.fd);
}

int main(int ac, char **av)
{
	if (ac == 2)
		ftif(av[1]);
	if (ac == 3)
		ftif_filename(av[1], av[2]);
	return (0);
}