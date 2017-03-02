/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 02:31:07 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/05 14:25:04 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_convert_alpha(char **table, char *str)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	c = 65;
	while (j < ft_count_hash(str))
	{
		i = 0;
		while (table[j][i])
		{
			if (table[j][i] == '#')
				table[j][i] = c;
			i++;
		}
		c++;
		j++;
	}
	return (table);
}
