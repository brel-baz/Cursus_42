/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:46:25 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/09 16:18:27 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Localiser la premiere occurence
**	d'un caractere dans une chaine
**	'\0' fait partie des caracteres localisables
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (++i < (int)ft_strlen(s) + 1)
		if (*(s + i) == (char)c)
			return ((char *)s + i);
	return (NULL);
}
