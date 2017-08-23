/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 03:13:37 by brel-baz          #+#    #+#             */
/*   Updated: 2017/08/23 05:54:47 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# define BASE "0123456789abcdef"
# define BASE_UP "0123456789ABCDEF"
union my_id
{
	char c;
	int	d;
	char *s;
	unsigned int u;
	unsigned int o;
	unsigned int x;
	unsigned int X;
	unsigned int p;
};
#endif
