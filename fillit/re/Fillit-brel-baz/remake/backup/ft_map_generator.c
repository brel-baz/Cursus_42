/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:37:44 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/05 14:22:43 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map_generator(int size)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	map = (char**)malloc(sizeof(char*) * size);
//	printf("%d\n", size);
	while (j < size)
	{
		i = 0;
		map[j] = (char*)malloc(sizeof(char) * size + 1);
		while (i < size)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
//	printf("%d\n", j);
	return (map);
}
