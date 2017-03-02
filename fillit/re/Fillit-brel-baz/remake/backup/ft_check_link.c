/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:14:36 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/07 08:09:07 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_link(char *str)
{
	int		i;
	int		flag;
	int		len;

	i = 0;
	flag = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((i + 5 < len && (str[i + 5] == '#')) ||
				(i - 5 >= 0 && (str[i - 5] == '#')) ||
				(i + 1 < len && (str[i + 1] == '#')) ||
				(i - 1 >= 0 && (str[i - 1] == '#')))
				flag = 1;
			else
			{
				printf("str:{\n%s\n}\ni:%d\n", str, i);
				return (0);
			}
		}
		i++;
	}
	return (flag);
}
