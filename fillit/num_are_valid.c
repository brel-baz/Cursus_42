/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_are_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:31:35 by jreszka           #+#    #+#             */
/*   Updated: 2017/01/12 19:44:51 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

int	num_are_valid(t_data data)
{
	data.tetri_nb = (data.char_nb + 1) / 21;
	if (data.char_nb < MIN_CHAR_NB
		|| data.char_nb > MAX_CHAR_NB
		|| (data.char_nb + 1) % (20 + 1) != 0
		|| (data.hash_nb / data.tetri_nb != NORMAL_HASH_NB)
		|| (data.dot_nb / data.tetri_nb != NORMAL_DOT_NB)
		|| (data.border_nl_nb / data.tetri_nb != 4)
		|| ((data.between_nl_nb + 1) / data.tetri_nb != 1))
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}
