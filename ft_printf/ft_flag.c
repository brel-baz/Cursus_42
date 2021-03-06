/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 04:57:49 by brel-baz          #+#    #+#             */
/*   Updated: 2017/08/25 08:16:11 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_hastag(char c, va_list ap, t_env *env)
{
	union my_id id;

	if (c == 'o')
	{
		id.o = va_arg(ap, unsigned int);
		ft_putstr("0");
		// ft_putnbr_base(id.o, 8, BASE);
		ft_putstr(ft_itoa_base(id.o, 8));
		env->len = env->len + ft_strlen(ft_itoa_base(id.o, 8) + 1);
	}
	if (c == 'x')
	{
		id.x = va_arg(ap, unsigned int);
		ft_putstr("0x");
		// ft_putnbr_base(id.x, 16, BASE);
		ft_putstr(ft_itoa_base(id.x, 16));
		env->len = env->len + ft_strlen(ft_itoa_base(id.x, 16)) + 2;
	}
	if (c == 'X')
	{
		id.X = va_arg(ap, unsigned int);
		ft_putstr("0X");
		// ft_putnbr_base(id.X, 16, BASE_UP);
		ft_putstr(ft_itoa_base_up(id.X, 16));
		env->len = env->len + ft_strlen(ft_itoa_base_up(id.X, 16) + 2);
	}
}

void	ft_flag_space(char c, va_list ap, t_env *env)
{
	union my_id id;

	if (c == 'd' || c == 'i')
	{
		id.d = va_arg(ap, int);
		if (id.d >= 0)
			ft_putchar(' ');
		// ft_putnbr(id.d);
		ft_putstr(ft_itoa(id.d));
		env->len = env->len + ft_strlen(ft_itoa(id.d)) + 1;
	}
}

void	ft_flag_more(char c, va_list ap, t_env *env)
{
	union my_id id;

	if (c == 'd' || c == 'i')
	{
		id.d = va_arg(ap, int);
		if (id.d >= 0)
			ft_putchar('+');
		// ft_putnbr(id.d);
		ft_putstr(ft_itoa(id.d));
		env->len = env->len + ft_strlen(ft_itoa(id.d)) + 1;
	}
}
