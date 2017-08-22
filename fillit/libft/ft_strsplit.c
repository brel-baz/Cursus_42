/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:58:42 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 16:47:12 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Alloue (avec malloc(3)) et retourne un tableau de chaines de
**	caractères “fraiches” (toutes terminées par un ’\0’, le tableau
**	également donc) résultant de la découpe de s selon le caractère
**	c. Si l’allocation echoue, la fonction retourne NULL. Exemple :
**	ft_strsplit("*salut*les***etudiants*", ’*’) renvoie
**	le tableau ["salut", "les", "etudiants"].
*/

#include "libft.h"

static int	get_word_len(char const *str, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_countwords(char const *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

/*
**	i = iteration dans le tableau de chaines
**	j = iterations dans les caracteres de la chaine de base
**	k = iteration dans un mot
*/

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**strtable;

	if (!s || !(strtable = (char **)malloc(sizeof(*strtable) *
		(ft_countwords(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if (!(strtable[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			strtable[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			strtable[i][k++] = s[j++];
		strtable[i][k] = '\0';
	}
	strtable[i] = 0;
	return (strtable);
}
