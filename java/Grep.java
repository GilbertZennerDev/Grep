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

/*
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
}*/

import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.stream.IntStream;
import java.util.stream.Collectors;
import java.nio.charset.StandardCharsets;

public class Grep
{
	public Grep(){}

	public void doGrep(String target, String filename, boolean contains)
	{
		BufferedReader reader;

		if (filename.equals("")){System.out.println("Error: No input given!"); return ;}
		//no filename given
		if (filename.equals("stdin")) //read from stdin
		{
			try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			if (contains)
			{
				reader.lines()
				.filter(line -> line.contains(target))
				.forEach(System.out::println);
			}
			else
			{
				reader.lines()
				.filter(line -> !line.contains(target))
				.forEach(System.out::println);
			}
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		else // we read from a file
		{
			List<String> dummyList = new ArrayList<>();
			try (var lines = Files.lines(Paths.get(filename))) {
			if (contains) lines.filter(line -> line.contains(target)).forEach(System.out::println);
			else lines.filter(line -> !line.contains(target)).forEach(System.out::println);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	public static void main(String[] args)
	{
	}
}
