/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2d_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:35:26 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/12 19:08:21 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void	ft_print_2d_table(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putstr(str[i]);
		ft_putstr("\n");
		i++;
	}
}
