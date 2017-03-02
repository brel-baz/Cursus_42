/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 02:31:07 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/29 04:33:51 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_size_map(char *str);

char	**ft_convert_alpha(char **table, char *str)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	c = 65;
	while (j < ft_size_map(str))
	{
		i = 0;
		while (table[j][i])
		{
			if (table[j][i] == '#')
				table[j][i] = c;
			i++;
		}
		printf("%s\n", table[j]);
		c++;
		j++;
	}
	return (table);
}
