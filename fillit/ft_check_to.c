/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 07:49:36 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/17 07:51:47 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	**ft_map_generator(int size);
int		ft_size_map(char *str);

int		ft_check_to(char **solve, char c,int n, char *str)
{
	int i;
	int j;
	int k;
	int count;


	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
		{
			j = i / 5;
			k = i % 5;
			c = solve[j+n][k+n];
			if (c == '.')
				count++;
		}
		i++;
	}
	return (count);
}
