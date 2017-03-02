/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decalage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:09:12 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/04 23:27:08 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>

char	**ft_decalage(char **solve, char c, int size)
{
	int i;
	int j;
	char tmp;

	
	j = 0;
	while (j < size)
	{
		i = 0;
		while (solve[i][j])
		{
			if (i + 1 < size)
			{
				ft_putnbr(size);
				ft_putchar('\n');
				if (solve[i][j] == c && solve[i + 1][j] == '.')
				{
					tmp = solve[j][i];
					solve[j][i + 1] = solve[j][i];
					solve[j][i] = tmp;
				}
			}
			i++;
		}
		j++;
	}
//	ft_putstr("ok");
/*	while (j < size)
	{
		i = 0;
		while (solve[j][i])
		{
			ft_putnbr(j);
			ft_putchar('\n');

			//si c'est le caratere c 
				// decaler

			if (solve[j][i] == c)
			{
				//si place a droite decaler a droite
				if (solve[j][i + 1] == '.')
				{
					ft_putstr("decalage a droite\n");
					solve[j][i + 1] = c;
					solve[j][i] = '.';
				}
				
				//sinon decaler en bas a gauche
				else if (j + 1 < size)
				{
					ft_putstr("decalage en bas\n");
					solve[j][i] = '.';
					i = 0;
					solve[j + 1][i] = c;
				}
			}

			if (i + 1 <= ft_strlen(solve[j]) && solve[j][i + 1] == '.')
			{
				ft_putstr("premier if\n");
				ft_putchar(c);
				if (solve[j][i] == c)
				{
					ft_putstr("2nd if\n");
					solve[j][i] = '.';
					solve[j][i + 1] = c;
				}
			}
			if (solve[j][i + 1] == '\0' && j + 1 < size)
			{
				ft_putstr("3nd if\n");
				if (solve[j][i + 1] == c)
				{
					solve[j][i + 1] = '.';
					i = 0;
					solve[j + 1][i] = c;
				}
			}

			i++;
		}
		j++;
	}*/
	return (solve);
}
