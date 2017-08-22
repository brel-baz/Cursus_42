/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:06:49 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/12 19:08:04 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_map	ft_build_tets(char **table, t_map map, t_data data)
{
	while (table[++map.table_i])
	{
		map.charac_i = -1;
		while (table[map.table_i][++map.charac_i])
		{
			if (table[map.table_i][map.charac_i] == '#')
			{
				map.tets[map.tets_i].hash[map.hash_i].x = map.charac_i;
				map.tets[map.tets_i].hash[map.hash_i].y = (map.table_i % 4);
				map.hash_i++;
			}
		}
		if ((map.table_i + 1) % 4 == 0)
		{
			map.tets_i++;
			map.hash_i = 0;
		}
	}
	map = ft_tets_ref_points(map, data);
	return (map);
}
