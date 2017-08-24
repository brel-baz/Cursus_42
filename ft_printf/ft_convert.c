/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 02:49:11 by brel-baz          #+#    #+#             */
/*   Updated: 2017/08/24 07:39:00 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_convert_1(char c, va_list ap, t_env *env)
{
	union my_id id;

	if (c == '%')
	{
		ft_putchar('%');
		env->len++;
	}
	if (c == 'c')
	{
		id.c = (char)va_arg(ap, int);
		ft_putchar(id.c);
		env->len++;
	}
	if (c == 'd' || c == 'i')
	{
		id.d = va_arg(ap, int);
		ft_putnbr(id.d);
		env->len = ft_strlen(ft_itoa(id.d));
	}
	if (c == 'u')
	{
		id.u = (unsigned int)va_arg(ap, int);
		ft_putnbr(id.u);
		env->len = ft_strlen(ft_itoa(id.u));
	}
	if (c == 's')
	{
		id.s = va_arg(ap, char*);
		ft_putstr(id.s);
		env->len = ft_strlen(id.s);
	}
}

void	ft_convert_2(char c, va_list ap)
{
	union my_id id;

	if (c == 'o')
	{
		id.o = va_arg(ap, unsigned int);
		ft_putnbr_base(id.o, 8, BASE);
	}
	if (c == 'x')
	{
		id.x = va_arg(ap, unsigned int);
		ft_putnbr_base(id.x, 16, BASE);
	}
	if (c == 'X')
	{
		id.X = va_arg(ap, unsigned int);
		ft_putnbr_base(id.X, 16, BASE_UP);
	}
	if (c == 'p')
	{
		id.p = va_arg(ap, unsigned int);
		ft_putstr("0x");
		ft_putnbr_base(id.p, 16, BASE);
	}
}
void	ft_convert(char c, va_list ap, t_env *env)
{
	ft_convert_1(c, ap, env);
	ft_convert_2(c, ap);
}
