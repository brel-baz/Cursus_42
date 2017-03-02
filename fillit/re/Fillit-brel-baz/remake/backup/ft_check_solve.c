/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 08:30:30 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/07 08:32:58 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_solve(char *str, char **tab, int x, int y, int size)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
		{
			if (i / 5 + x < size)
			{
			/*	printf("i:%d	x:%d	y:%d\nid1:{%d, %d}	id2:{%d, %d}\n", i, x, y,
						(i / 5 + x), (i % 5 + y),
						(i / 5 + x), (i % 5 + y));*/
				if ((i % 5 + y < size) && (tab[i / 5 + x][i % 5 + y] == '.' &&
						tab[i / 5 + x][i % 5 + y] != '\0'))
				flag++;
			}
		else
			return (- 1);
		}
		i++;
	}
	return (flag);
}
