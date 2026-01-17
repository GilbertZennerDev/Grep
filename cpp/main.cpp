/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:16 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/06 16:49:43 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

void grep(string target, string filename)
{
	int		i;
	string		t;
	vector<string>	content;

	if (filename.size() == 0)
	{
		cout << "Error, no input given.\n";
		return ;
	}
	else if (filename == "stdin")
	{
		while (getline(cin, t))
		{
			content.push_back(t);
		}
	}
	else
	{
		try
		{
			ifstream file(filename);
			while (getline(file, t))
			{
				content.push_back(t);
			}
			file.close();
		}
		catch (exception e)
		{
			cout << "Error Reading File " << filename << "\n";
		}
	}
	i = -1;
	while (++i < content.size())
	{
		if (content[i].find(target) != -1) cout << "Line " << i << ": " << content[i] << "\n";
	}
}

int	main(int ac, char **av)
{
	if (ac == 3) grep(av[2], av[1]);
	else cout << "Usage ./GREP target filename.\n";
	return (0);
}
