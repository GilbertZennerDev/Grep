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
