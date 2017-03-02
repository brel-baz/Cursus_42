/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:12:34 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/14 02:17:29 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_high(char *str);
int		ft_check_left(char *str);
char	*ft_move_high(char *str);
char	*ft_move_left(char *str);

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
