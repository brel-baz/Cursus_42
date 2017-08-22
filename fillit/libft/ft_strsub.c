/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:58:47 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 16:15:02 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un
**	tronçon de la chaine de caractères passée en paramètre. Le
**	tronçon commence à l’index start et à pour longueur len. Si
**	start et len ne désignent pas un tronçon de chaine valide,
**	le comportement est indéterminé. Si l’allocation échoue, la
**	fonction renvoie NULL.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	new_str = ft_strnew(len);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
		*(new_str + i++) = *(s + start++);
	return (new_str);
}
