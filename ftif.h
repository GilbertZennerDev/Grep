/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftif.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:36:32 by gzenner           #+#    #+#             */
/*   Updated: 2025/07/28 16:52:54 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTIF_H
#define FTIF_H

#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "/home/gzenner/active/libft/libft.h"

typedef struct s_data
{
	int fd;
	char buffer[1024];
	int bytes_read;
    char *target;
    char *filename;
    unsigned int i;
	unsigned int j;
	unsigned int line_index;
}   t_data;

#endif