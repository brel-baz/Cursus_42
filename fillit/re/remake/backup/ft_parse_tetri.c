/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:12:34 by brel-baz          #+#    #+#             */
/*   Updated: 2017/01/05 14:19:01 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_parse_tetri(char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_check_high(str) == 4)
			ft_move_high(str);
		if (ft_check_left(str) == 4)
			ft_move_left(str);
		i++;
	}
	return (str);
}
