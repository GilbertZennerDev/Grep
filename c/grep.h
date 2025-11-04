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
# include <fcntl.h>
# include "/home/gzenner/active/libft/libft.h"

typedef struct s_data
{
	int				fd;
	char			*target;
	char			*mbuffer;
	char			*filename;
	char			buffer[1024 * 1024];
}	t_data;

void			closeonerror(int bytes_read);
void			minicalloc_char(char buffer[]);
int				ft_strstr(char *haystack, char *needle);

#endif
