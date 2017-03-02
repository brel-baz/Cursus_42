/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:52:15 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/13 20:21:13 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_map(char *str);
char	*ft_tetris_str(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*solve;

	i = 0;
	j = 0;
	len =  ft_size_map(str) * ft_size_map(str) + ft_size_map(str) - 1;
	solve = (char*)malloc(sizeof(char) * len);
	while (i < len)
	{
		if (j == ft_size_map(str))
		{
			solve[i] = '\n';
			j = -1;
		}
		else
			solve[i] = '.';
		i++;
		j++;
	}
	solve[i] = '\0';
	return (solve);
}
