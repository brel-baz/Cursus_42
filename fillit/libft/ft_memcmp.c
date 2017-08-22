/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:24:02 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 14:03:52 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Compare les bytes de s1 avec s2
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int			i;
	unsigned const char		*ps1;
	unsigned const char		*ps2;

	ps1 = s1;
	ps2 = s2;
	i = 0;
	while (i < n && (ps1 || ps2))
	{
		if (ps1[i] != ps2[i])
			return ((int)(ps1[i] - ps2[i]));
		i++;
	}
	return (0);
}
