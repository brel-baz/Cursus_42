/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:51:12 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/09 16:19:39 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Ajoute une copie pas plus de n caracteres
**	de s2 qui se termine par '\0'
**	a la fin de s1 qui se termine par '\0'
**	Ajoute un '\0' a la fin
**	s1 doit avoir suffisament de place.
**	Retourne un pointeur vers s1
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] && j < n)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
