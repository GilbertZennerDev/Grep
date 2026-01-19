/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:28 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/04 16:10:53 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREP_H
# define GREP_H
# define READ_SIZE 1000000000
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_data
{
	int				fd;
	char			*target;
	char			*mbuffer;
	char			*filename;
	char			buffer[READ_SIZE];
}	t_data;

void			closeonerror(int bytes_read);
void			minicalloc_char(char buffer[]);
int				ft_strstr(char *haystack, char *needle);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
