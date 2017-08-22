/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:55:02 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 14:06:16 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Alloue suffisament de memoire pour une copie du string s1
**	Apres avoir fait le copie la retourne
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *ret;

	ret = (char *)malloc(sizeof(*ret) * ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	ft_strcpy(ret, s);
	return (ret);
}
