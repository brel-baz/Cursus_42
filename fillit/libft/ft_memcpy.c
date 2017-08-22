/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:33:32 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 11:59:19 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Copie n bytes depuis src vers dst.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		i++;
	}
	return (dst);
}
