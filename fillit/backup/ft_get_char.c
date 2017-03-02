/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:19:18 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/03 17:23:32 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	ft_get_char(char *str)
{
	char c;
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			c = str[i];
		i++;
	}
	return (c);
}
