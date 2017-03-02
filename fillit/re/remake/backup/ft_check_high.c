/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_high.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:33:12 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/05 14:26:24 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_high(char *str)
{
	int		i;
	int		j;
	char	tmp;
	char	*str2;

	i = 0;
	j = 0;
	str2 = (char*)malloc(sizeof(char) * ft_strlen(str));
	ft_strcpy(str2, str);
	while (str2[i])
	{
		if (i - 5 >= 0)
		{
			if (str2[i] == '#' && str2[i - 5] == '.')
			{
				tmp = str2[i - 5];
				str2[i - 5] = str2[i];
				str2[i] = tmp;
				j++;
			}
		}
		i++;
	}
	return (j);
}
