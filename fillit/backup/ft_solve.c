/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 04:07:47 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/04 15:58:54 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_size_map(char *str);
int		ft_count_hash(char *str);
char	**ft_map_generator(int size);
int		ft_check_solve(char *str, char **tab, int x, int y, int size);
char	ft_get_char(char *str);
char	**ft_decalage(char **solve, char c, int size);

int		ft_solve(char **tab, char *str, int x, int y, int size)
{
	char **solve;
	int i;
	int ligne;
	int k;
	int tetri_nb;
	int check_placed = 0;
	int l = 0;

	solve = ft_map_generator(size);
	ligne = - 1;
	tetri_nb = ft_count_hash(str);
	// Iteration dans le tableau de tetriminos de 21 characteres
	while (++ligne < tetri_nb)
	{
		i = - 1;
		y = 0;
		x = 0;
		// Tant que il est possible de placer des tetriminos dans le tableau solve (la map avec les ...)
		while (ft_check_solve(tab[ligne], solve, x, y, size) != 4)
		{ 
		if (l == 100000000)
				return (0);
			y++;
			// Descendre d'une ligne si on arrive a la fin de la ligne de la carte
			if (solve[x][y] == '\0')
			{
				x++;
				y = 0;
			}
			// Si on ne peut plus placer de tetris sur la map
			if (ft_check_solve(tab[ligne], solve, x, y, size) == - 1)
			{
				// Decaler le dernier tetris pose vers la droite et reesayer de placer le tetris ou vers le bas
				
					ft_putchar(ft_get_char(tab[ligne - 1]));
					ft_putchar('\n');
		 			ft_decalage(solve, ft_get_char(tab[ligne - 1]), size);
			 		ft_putstr("decalage\n");
			 		ligne--;
			 		l++;
			 		break;
			}
			/*else if (ft_check_solve(tab[ligne], solve, x, y, size) == - 1)
			{
				free(solve);
				size++;
				solve = ft_map_generator(size);
				ligne = 0;
				x = 0;
				y = 0;
				break;
			}*/
		}
		if (ft_check_solve(tab[ligne], solve, x, y, size) == 4)
		{
			while (tab[ligne][++i])
			{
				if (ft_isalpha(tab[ligne][i]) == 1)
					solve[i / 5 + x][i % 5 + y] = tab[ligne][i];
			
			}
			check_placed++;
		}
	}
	if (check_placed != tetri_nb)
		return (0);

	k = 0;
	while (k < size)
	{
		printf("%s\n", solve[k]);
		k++;
	}
	return (1);
}
