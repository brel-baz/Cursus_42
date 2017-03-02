/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_high.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:30:12 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/05 14:22:48 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_move_high(char*str)
{
	int		i;
	char	tmp;

	i = 0;
	while (str[i])
	{
		if (i - 5 >= 0)
		{
			if (str[i] == '#' && str[i - 5] == '.')
			{
				tmp = str[i - 5];
				str[i - 5] = str[i];
				str[i] = tmp;
			}
		}
		i++;
	}
	return (str);
}
