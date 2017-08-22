/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:57:01 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 12:13:41 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Copie tous les caracteres de src vers dst jusqu'a ce que c est rencontre
**	Renvoie l'adresse memoire apres le caractere c rencontre dans dst
**	Sinon renvoie NULL
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = dst;
	while (++i < n)
	{
		*(ptr + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
