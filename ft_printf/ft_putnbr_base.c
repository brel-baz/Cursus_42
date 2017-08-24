/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 02:56:41 by brel-baz          #+#    #+#             */
/*   Updated: 2017/08/23 22:36:55 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

##include "ft_printf.h"

void	ft_putnbr_base(int nbr, int base)
{
	if (nbr == 0)
		return;
	ft_putnbr_base(nbr / base, base);
	ft_putchar(BASE[nbr % base]);
}
