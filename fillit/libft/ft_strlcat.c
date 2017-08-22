/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:01:37 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/09 16:19:05 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Version plus safe de strncat
**	Si la taille de la destination est superieure a la size
**	Retourne la taille de la source + la size
**	Sinon
**	Retourne la somme des tailles de la dst et de la src
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int dst_len;
	unsigned int src_len;
	unsigned int j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = 0;
	if (size < dst_len + 1)
		return (src_len + size);
	if (size > dst_len + 1)
	{
		while (src[j] && j < size - dst_len - 1)
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		dst[dst_len + j] = '\0';
	}
	return (dst_len + src_len);
}
