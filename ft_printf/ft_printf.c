/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 05:11:15 by brel-baz          #+#    #+#             */
/*   Updated: 2017/08/23 06:03:59 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, int base, char *cbase)
{
	if (nbr == 0)
		return;
	ft_putnbr_base(nbr / base, base, cbase);
	ft_putchar(cbase[nbr % base]);
}

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
			if (format[i + 1] == '%')
				ft_putchar('%');

			if (format[i + 1] == 'c')
			{
				id.c = (char)va_arg(ap, int);
				ft_putchar(id.c);
			}

			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				id.d = va_arg(ap, int);
				ft_putnbr(id.d);
			}
			if (format[i + 1] == 'u')
			{
				id.u = (unsigned int)va_arg(ap, int);
				ft_putnbr(id.u);
			}
			if (format[i + 1] == 's')
			{
				id.s = va_arg(ap, char*);
				ft_putstr(id.s);
			}
			if (format[i + 1] == 'o')
			{
				id.o = va_arg(ap, unsigned int);
				ft_putnbr_base(id.o, 8, BASE);
			}
			if (format[i + 1] == 'x')
			{
				id.x = va_arg(ap, unsigned int);
				ft_putnbr_base(id.x, 16, BASE);
			}
			if (format[i + 1] == 'X')
			{
				id.X = va_arg(ap, unsigned int);
				ft_putnbr_base(id.X, 16, BASE_UP);
			}
			if (format[i + 1] == 'p')
			{
				id.p = va_arg(ap, unsigned int);
				ft_putstr("0x");
				ft_putnbr_base(id.p, 16, BASE);
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

int 	main()
{
	int i;
	int j;
	int k;
	char c = 'Z';
	char str[5] = "test";

	i = 420;
	j = 90;
	k = 78;
	printf("printf1 = %p\n", &str);
	ft_printf("ft_printf = %p\n", &str);
	ft_putchar('\n');
	printf("printf i = %d , j = %d , k = %d, %s , %% , %c\n", i,j,k, str,c);
	ft_printf("ft_printf i = %d , j = %d , k = %d, %s , %%, %c\n", i,j,k, str,c);
	return (0);
}
