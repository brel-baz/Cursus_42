/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 05:11:15 by brel-baz          #+#    #+#             */
/*   Updated: 2017/08/24 07:52:23 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, int base, char *cbase)
{
	if (nbr == 0)
		return ;
	ft_putnbr_base(nbr / base, base, cbase);
	ft_putchar(cbase[nbr % base]);
}

int		ft_printf(const char *format, ...)
{
	int i;
	va_list ap;
	t_env *env;

	va_start(ap, format);
	i = 0;
	env = (t_env*)malloc(sizeof(t_env));
	env->len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '#')
			{
				ft_flag_hastag(format[i + 2], ap);
				i++;
			}
			else if (format[i + 1] == ' ')
			{
				ft_flag_space(format[i + 2], ap, env);
				i++;
			}
			else if (format[i + 1] == '+')
			{
				ft_flag_more(format[i + 2], ap, env);
				i++;
			}
			else
				ft_convert(format[i + 1], ap, env);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			env->len++;
		}
		i++;
	}
	va_end(ap);
	return (env->len);
}

// int 	main()
// {
// 	int i;
// 	int j;
// 	int k;
// 	char c = 'Z';
// 	char str[5] = "test";
//
// 	i = 420;
// 	j = 90;
// 	k = 78;
// 	printf("printf1 = %+10d\n", i);
// 	ft_printf("ft_printf = %d\n", i);
// 	ft_putchar('\n');
// 	printf("printf i = %d , j = %d , k = %d, %s , %% , %c\n", i,j,k, str,c);
// 	ft_printf("ft_printf i = %d , j = %d , k = %d, %s , %% , %c\n", i,j,k, str,c);
// 	// ft_printf("111%s333%s555", "222", "444");
// 	// ft_putchar('\n');
// 	// printf("111%s333%s555", "222", "444");
// 	return (0);
// }
