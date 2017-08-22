/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:58:28 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 16:40:56 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Alloue (avec malloc(3)) et retourne une chaine de caractère
**	“fraiche” terminée par un ’\0’. Chaque caractère de la chaine
**	est initialisé à ’\0’. Si l’allocation echoue, la fonction renvoie NULL
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
