/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:58:39 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/09 16:21:47 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Localiser la derniere occurence
**	d'un caractere dans une chaine
**	'\0' fait partie des caracteres localisables
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen(s) + 1;
	while (i--)
		if (*(s + i) == (char)c)
			return ((char *)s + i);
	return (NULL);
}
