/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:45:30 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/16 17:15:24 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_map	ft_init_map(t_map map, t_data data)
{
	int height;
	int width;

	map.size = ft_int_sqrt(data.hash_nb);
	map.table_i = -1;
	map.tets_i = 0;
	map.hash_i = 0;
	map.charac_i = 0;
	map.tets = (t_tet*)malloc(sizeof(t_tet) * (data.hash_nb / 4 + 1));
	map.placed_tets_nb = 0;
	map.content = (char**)malloc(sizeof(char*) * (map.size + 1));
	height = -1;
	while (++height < map.size)
	{
		map.content[height] = (char*)malloc(sizeof(char) * (map.size + 1));
		width = -1;
		while (++width < map.size)
		{
			map.content[height][width] = '.';
		}
		map.content[height][width] = '\0';
	}
	map.content[height] = 0;
	return (map);
}
