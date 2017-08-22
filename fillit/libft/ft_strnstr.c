/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:58:35 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/09 16:43:24 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Trouver une chaine dans une chaine
**	La premiere occurence
**	Dans un searchspace limite a len
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = -1;
	found = 1;
	if (little[0] == '\0')
		return ((char *)big);
	while (*(big + ++i) && i < len)
	{
		j = 0;
		if (*(big + i) == *(little + 0))
		{
			k = i;
			found = 1;
			while (*(big + k) && *(little + j) && j < len && k < len)
				if (*(big + k++) != *(little + j++))
					found = 0;
			if (found && !*(little + j))
				return ((char *)big + i);
		}
	}
	return (NULL);
}
