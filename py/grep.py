# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grep.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 22:35:06 by pinkwish          #+#    #+#              #
#    Updated: 2025/11/03 09:54:53 by gzenner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def grep(filename, target):
    content = open(filename, 'r').read().splitlines()
    for i, line in enumerate(content):
        if target in line:
            print("Line", i, ":", line)
            
grep(sys.argv[1], sys.argv[2])
