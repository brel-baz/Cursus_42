/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decalage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:09:12 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/10 08:37:28 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

char	**ft_decalage(char **solve, char c, int size)
{
	/*if (ft_check_right(solve, c, size) == 4)
	{
		ft_move_right(solve, c, size);
	}
	else if (ft_check_bottom(solve, c, size) == 4)
	{
		ft_move_bottom(solve, c, size);
	}
	else
		return (solve);*/
	int x = 0;
	int y;
	while (x < size)
	{
		y = 0;
		while (solve[x][y])
		{
			if (solve[x][y] == c)
				solve[x][y] = '.';
			y++;
		}
		x++;
	}
	return (solve);
}
