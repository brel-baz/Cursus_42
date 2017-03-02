/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_high.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:30:12 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/13 18:45:26 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

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
