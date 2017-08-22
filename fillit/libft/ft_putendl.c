/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:57:19 by jreszka           #+#    #+#             */
/*   Updated: 2016/11/11 17:16:51 by jreszka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Affiche la chaine s sur la sortie standard suivi d’un ’\n’.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}
