/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:22:09 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 14:10:19 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Trouve la premiere occurence de c dans la chaine s
**	Renvoie un pointeur vers la position
**	Renvoie NULL is ne trouve pas dans les n bytes
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
