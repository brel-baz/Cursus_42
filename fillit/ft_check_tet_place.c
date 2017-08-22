/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tet_place.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:58:49 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/25 17:20:17 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		can_place_tet(int i, t_map map, int pos_x, int pos_y)
{
	int available_places;
	int j;
	int x;
	int y;

	available_places = 0;
	j = 0;
	while (j < 4)
	{
		y = pos_y + map.tets[i].hash[j].y - map.tets[i].ref_min.y;
		x = pos_x + map.tets[i].hash[j].x - map.tets[i].ref_min.x;
		if (x < map.size && y < map.size)
		{
			if (map.content[y][x] == '.')
				available_places++;
		}
		j++;
	}
	if (available_places == 4)
		return (1);
	return (0);
}

void	place_tet(int i, t_map map, int pos_x, int pos_y)
{
	int j;
	int x;
	int y;

	j = 0;
	while (j < 4)
	{
		y = pos_y + map.tets[i].hash[j].y - map.tets[i].ref_min.y;
		x = pos_x + map.tets[i].hash[j].x - map.tets[i].ref_min.x;
		map.content[y][x] = map.tets[i].lettre;
		j++;
	}
}

int		can_move_tet_right(int i, t_map map)
{
	if (map.tets[i].width + map.tets[i].pos.x < map.size)
		return (1);
	return (0);
}

int		can_move_tet_bottom(int i, t_map map)
{
	if (map.tets[i].height + map.tets[i].pos.y < map.size)
		return (1);
	return (0);
}

int		can_displace_tetri(int i, t_map map)
{
	if (can_move_tet_right(i, map)
		|| can_move_tet_bottom(i, map))
	{
		return (1);
	}
	return (0);
}
