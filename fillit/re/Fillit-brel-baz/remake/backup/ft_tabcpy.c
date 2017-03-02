/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:40:14 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/05 14:53:45 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tabcpy(char **tab, int size)
{
	char	**tab2;

	tab2 = (char**)malloc(sizeof(char*) * size);
	while (j < size)
	{
		i = 0;
		tab2[j] = (char*)malloc(sizeof(char) * size + 1);
		while (i < size)
		{
			tab2[j][i] = tab[j][i];
			i++;
		}
		tab2[j][i] = '\0';
		j++;
	}
	return (tab2);
}