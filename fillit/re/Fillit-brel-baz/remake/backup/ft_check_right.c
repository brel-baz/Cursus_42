/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:58:08 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/05 17:17:02 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_right(char **solve, char c, int size)
{
	int flag;
	int x;
	int y;

	x = 0;
	flag = 0;
	while (x < size)
	{
		y = 0;
		while (solve[x][y])
		{
			if (solve[x][y] == c && solve[x][y + 1] == '.' && y + 1 < size)
			{
				solve[x][y] = '.';
				solve[x][y + 1] = c;
				flag++;
			}
			y++;
		}
		x++;
	}
	return (flag);
}
