# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ftif.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pinkwish <pinkwish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 22:35:06 by pinkwish          #+#    #+#              #
#    Updated: 2025/07/26 23:16:23 by pinkwish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def ftif(filename, target):
    content = open(filename, 'r').read().splitlines()
    for i, line in enumerate(content):
        if target in line:
            print(line, i)