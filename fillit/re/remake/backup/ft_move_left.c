/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:29:06 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/05 14:22:51 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_move_left(char*str)
{
	int		i;
	char	tmp;

	i = 0;
	while (str[i])
	{
		if (i - 1 >= 0)
		{
			if (str[i] == '#' && str[i - 1] == '.')
			{
				tmp = str[i - 1];
				str[i - 1] = str[i];
				str[i] = tmp;
			}
		}
		i++;
	}
	return (str);
}
