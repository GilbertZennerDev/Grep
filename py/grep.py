# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grep.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 22:35:06 by pinkwish          #+#    #+#              #
#    Updated: 2025/11/04 15:51:26 by gzenner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def grep(target, filename=None):
    if filename is None:
        content = sys.stdin.read().splitlines()
    else:
        with open(filename, 'r') as f:
            content = f.read().splitlines()

    for i, line in enumerate(content, start=1):
        if target in line:
            print(f"Line {i}: {line}")

if __name__ == '__main__':
    if len(sys.argv) == 3:
        grep(sys.argv[2], sys.argv[1])
    elif len(sys.argv) == 2:
        grep(sys.argv[1])
