/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:31:35 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/12 19:09:01 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_data	parse(char *buf, t_data data)
{
	int		j;

	data.char_nb = 0;
	data.hash_nb = 0;
	data.dot_nb = 0;
	data.border_nl_nb = 0;
	data.between_nl_nb = 0;
	j = 1;
	while (buf[data.char_nb])
	{
		if (buf[data.char_nb] == '#')
			data.hash_nb++;
		if (buf[data.char_nb] == '.')
			data.dot_nb++;
		if ((j) % 5 == 0 && buf[data.char_nb] == '\n')
			data.border_nl_nb++;
		if ((data.char_nb + 1) % 21 == 0 && buf[data.char_nb] == '\n')
		{
			data.between_nl_nb++;
			j--;
		}
		data.char_nb++;
		j++;
	}
	return (data);
}
