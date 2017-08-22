/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:45:57 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/25 17:20:30 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int		first_tetri_can_be_displaced(t_map map)
{
	return (can_displace_tetri(0, map));
}

int		is_placed_tet(int i, t_map map)
{
	if (can_place_tet(i, map, map.tets[i].pos.x, map.tets[i].pos.y))
	{
		place_tet(i, map, map.tets[i].pos.x, map.tets[i].pos.y);
		return (1);
	}
	return (0);
}

t_map	init_tets_pos(t_map map, t_data data)
{
	int i;

	i = 0;
	while (i < (data.hash_nb / 4))
	{
		map.tets[i].pos.x = 0;
		map.tets[i].pos.y = 0;
		i++;
	}
	return (map);
}

t_map	try_place_all_tets(t_map map)
{
	if (is_placed_tet(map.placed_tets_nb, map))
	{
		map.placed_tets_nb++;
	}
	else if (map.tets[map.placed_tets_nb].pos.y < map.size)
	{
		map = move_tet_pos(map.placed_tets_nb, map);
	}
	else
	{
		map.tets[map.placed_tets_nb].pos.y = 0;
		map.tets[map.placed_tets_nb].pos.x = 0;
		map.placed_tets_nb--;
		map = rm_tet(map.placed_tets_nb, map);
		map = move_tet_pos(map.placed_tets_nb, map);
	}
	return (map);
}

int		ft_solve(t_map map, t_data data)
{
	while (map.placed_tets_nb != (data.hash_nb / 4))
	{
		map = init_tets_pos(map, data);
		while (first_tetri_can_be_displaced(map))
		{
			if (map.placed_tets_nb == -1)
				break ;
			if (map.placed_tets_nb == (data.hash_nb / 4))
			{
				ft_print_2d_table(map.content);
				return (0);
			}
			map = try_place_all_tets(map);
		}
		map.size++;
		map = make_map_bigger(map);
	}
	return (0);
}
