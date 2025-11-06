/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:16 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/06 16:49:43 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grep.hpp"

void	printline(std::string line, std::string target)
{
	if (line.find(target) != std::string::npos) std::cout << line << "\n";
}

void	Grep::browsembuffer(t_data *data)
{
	int			nl;
	std::string	line;

	while ((nl = data->mbuffer.find('\n')) >= 0)
	{
		line = data->mbuffer.substr(0, nl);
		printline(line, data->target);
		data->mbuffer = data->mbuffer.substr(nl + 1);
	}
	if (nl < 0) printline(data->mbuffer, data->target);
}

void	Grep::grep_filename(const char *filename, const char *target)
{
	t_data	data;

	data.target = target;
	std::ifstream MyFile(filename);
	if (MyFile.is_open()) {
    std::string content((std::istreambuf_iterator<char>(MyFile)),
                         std::istreambuf_iterator<char>());
    data.mbuffer = content;
} else {
    std::cerr << "Error: Could not open file " << filename << "\n";
}
  	MyFile.close();
	browsembuffer(&data);
}

void	Grep::grep(const char *target)
{
	t_data	data;

	data.target = target;
	getline(std::cin, data.mbuffer);
	browsembuffer(&data);
}

int	main(int ac, char **av)
{
    Grep grep = Grep();
	if (ac == 2) grep.grep(av[1]);
	if (ac == 3) grep.grep_filename(av[1], av[2]);
	return (0);
}
