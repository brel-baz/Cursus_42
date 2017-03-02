/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:14:36 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/05 14:22:00 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_link(char *str)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((str[i + 5] == '#') || (str[i - 5] == '#') ||
				(str[i + 1] == '#') || (str[i - 1] == '#'))
				flag = 1;
			else
				return (0);
		}
		i++;
	}
	return (flag);
}
