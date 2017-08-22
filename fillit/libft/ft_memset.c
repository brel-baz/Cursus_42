/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:12:32 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 11:54:21 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Ecrit un caractere c len fois sur le sur la chaine *b
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;

	s = b;
	while (len > 0)
	{
		*s++ = (unsigned char)c;
		len--;
	}
	return (b);
}
