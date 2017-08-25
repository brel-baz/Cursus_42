/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 03:13:37 by brel-baz          #+#    #+#             */
/*   Updated: 2017/08/25 08:16:20 by brel-baz         ###   ########.fr       */
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

typedef struct s_env
{
	int    len;
}			t_env;

void	ft_convert(char c, va_list ap, t_env *env);
void	ft_flag_hastag(char c, va_list ap, t_env *env);
void	ft_flag_space(char c, va_list ap, t_env *env);
void	ft_flag_more(char c, va_list ap, t_env *env);
void	ft_putnbr_base(unsigned int nbr, int base, char *cbase);
char	*ft_itoa_base(int value, int base);
char	*ft_itoa_base_up(int value, int base);
int		ft_pow(int nb, int pow);
char	*ft_utoa(unsigned int n);
#endif
