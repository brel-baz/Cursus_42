/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 08:30:30 by brel-baz          #+#    #+#             */
/*   Updated: 2016/12/29 09:20:14 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_map(char *str);

int		ft_check_solve(char *str, char **tab)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
		{
			if (tab[i /5][i % 5] == '.')
				flag++;
		}
		i++;
	}
	return (flag);
}
