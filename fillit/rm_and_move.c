/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_and_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:45:57 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/25 17:07:53 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_map	rm_tet(int i, t_map map)
{
	map.pos.y = 0;
	while (map.pos.y < map.size)
	{
		map.pos.x = 0;
		while (map.pos.x < map.size)
		{
			if (map.content[map.pos.y][map.pos.x] == map.tets[i].lettre)
				map.content[map.pos.y][map.pos.x] = '.';
			map.pos.x++;
		}
		map.pos.y++;
	}
	return (map);
}

t_map	move_tet_pos(int i, t_map map)
{
	if (map.tets[i].pos.x + map.tets[i].width < map.size)
	{
		map.tets[i].pos.x++;
	}
	else
	{
		map.tets[i].pos.x = 0;
		map.tets[i].pos.y++;
	}
	return (map);
}
