/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:56:38 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 17:12:49 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Alloue (avec malloc(3)) et retourne une chaine de caractères
**	“fraiche” terminée par un ’\0’ représentant l’entier n passé
**	en paramètre. Les nombres négatifs doivent être gérés. Si l’allocation
**	échoue, la fonction renvoie NULL.
*/

#include "libft.h"

static size_t	get_str_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			str_len;
	unsigned int	n_cpy;

	str_len = get_str_len(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		str_len++;
	}
	if (!(str = ft_strnew(str_len)))
		return (NULL);
	str[--str_len] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		str[--str_len] = n_cpy % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
