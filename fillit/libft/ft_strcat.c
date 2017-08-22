/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:23:31 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/09 16:17:48 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Ajoute une copie de s2 qui se termine par '\0'
**	a la fin de s1 qui se termine par '\0'
**	Ajoute un '\0' a la fin
**	s1 doit avoir suffisament de place.
**	Retourne un pointeur vers s1
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
