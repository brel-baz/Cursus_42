/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:37:44 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/03 14:59:37 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

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
