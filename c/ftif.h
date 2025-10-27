/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftif.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:36:32 by gzenner           #+#    #+#             */
/*   Updated: 2025/10/27 08:34:10 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTIF_H
# define FTIF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include "/home/gzenner/active/libft/libft.h"

typedef struct s_data
{
	unsigned int	i;
	unsigned int	j;
	int				fd;
	char			*target;
	char			*filename;
	char			buffer[1024];
	unsigned int	line_index;
}	t_data;

#endif
