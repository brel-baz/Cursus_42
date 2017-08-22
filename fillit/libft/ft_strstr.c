/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:05:59 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/09 16:31:15 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Trouver une chaine dans une chaine
**	La premiere occurence
*/

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		if (big[i + j] == little[j])
		{
			while (big[i + j] == little[j] && big[i + j] && little[j])
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
