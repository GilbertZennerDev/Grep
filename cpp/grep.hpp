/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:19:28 by gzenner           #+#    #+#             */
/*   Updated: 2025/11/06 16:44:49 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GREP_H
# define GREP_H
# include <string>
# include <iostream>
# include <fstream>

typedef struct s_data
{
	std::string		target;
	std::string		mbuffer;
	std::string		filename;
}	t_data;

class Grep
{
	public:
		void	grep_filename(const char *filename, const char *target);
		void	grep(const char *target);
	private:
		void	closeonerror(int bytes_read);
		void	browsembuffer(t_data *data);
};

#endif
