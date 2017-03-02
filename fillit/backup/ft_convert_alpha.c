/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 02:31:07 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/01 17:55:03 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_count_hash(char *str);

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
		printf("%s\n", table[j]);
		c++;
		j++;
	}
	return (table);
}
