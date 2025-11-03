/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:28 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/03 11:21:13 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREP_H
# define GREP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "/home/gzenner/active/libft/libft.h"

typedef struct s_data
{
	unsigned int	i;
	unsigned int	j;
	int				fd;
	unsigned int	end;
	char			*sub;
	unsigned int	start;
	char			*target;
	char			*mbuffer;
	char			*filename;
	unsigned int	line_index;
	char			buffer[1024 * 1024];
}	t_data;

void			closeonerror(int bytes_read);
void			ft_browse_stream(t_data *data);
void			minicalloc_char(char buffer[]);
void			ft_print_substring(t_data *data);
int				ft_strstr(char *haystack, char *needle);

#endif
