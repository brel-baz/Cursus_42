/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bigger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:02:38 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/12 19:08:46 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_map	make_map_bigger(t_map map)
{
	int height;
	int width;

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
