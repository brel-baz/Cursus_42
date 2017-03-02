/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bottom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:58:08 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/05 17:19:51 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_bottom(char **solve, char c, int size)
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
			if (solve[x][y] == c && solve[x + 1][y] == '.' && x + 1 < size)
			{
				solve[x][y] = '.';
				solve[x + 1][y] = c;
				flag++;
			}
			y++;
		}
		x++;
	}
	ft_putstr("flag :");
	ft_putnbr(flag);
	ft_putstr("\n");
	return (flag);
}
