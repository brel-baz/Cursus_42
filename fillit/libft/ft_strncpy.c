/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:26:29 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/09 16:20:10 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	copie au maximum len nombre de caractere depuis
**	la source src vers la destination dst.
**	Si src est plus petit que le nombre len de caracteres,
**	les caracteres restants sont des '\0'
**	Sinon la destination n'est pas terminee par '\0'
**	Renvoie la destination dst.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
