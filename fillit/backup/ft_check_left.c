/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:35:10 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/13 18:44:56 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_left(char *str)
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
		if (i - 1 >= 0)
		{
			if (str2[i] == '#' && str2[i - 1] == '.')
			{
				tmp = str2[i - 1];
				str2[i - 1] = str2[i];
				str2[i] = tmp;
				j++;
			}
		}
		i++;
	}
	return (j);
}
