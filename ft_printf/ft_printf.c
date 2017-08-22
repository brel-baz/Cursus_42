/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 05:11:15 by brel-baz          #+#    #+#             */
/*   Updated: 2017/08/22 07:31:04 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int i;
	union my_id id;
	va_list ap;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				id.c = (char)va_arg(ap, int);
				ft_putchar(id.c);
			}
			if (format[i + 1] == 'd')
			{
				id.d = va_arg(ap, int);
				ft_putnbr(id.d);
			}
			if (format[i + 1] == 's')
			{
				id.s = va_arg(ap, char*);
				ft_putstr(id.s);
			}
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (0);
}

// int 	main()
// {
// 	int i;
// 	int j;
// 	int k;
// 	char c = 'Z';
// 	char str[5] = "test";
//
// 	i = 42;
// 	j = 90;
// 	k = 78;
// 	// char c = 'N';
// 	// printf("%c\n", c);
// 	ft_printf("%c\n", c);
// 	return (0);
// }
