/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 08:30:30 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/22 05:29:54 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_solve(char *str, char **tab, int x, int y, int size)
{
	int i;
	int flag;
	// printf("yoyo == start\n");
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
		{
			if (i / 5 + x < size)
			{
				if ((tab[i / 5 + x][i % 5 + y] == '.' &&
						tab[i / 5 + x][i % 5 + y] != '\0'))
				flag++;
			}
		else
			return (- 1);
		}
		i++;
	}
	// printf("yoyo == end\n");
	return (flag);
}
