/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:44:03 by brel-baz          #+#    #+#             */
/*   Updated: 2016/11/10 05:54:46 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if ((nb >= 2) && (nb <= 12))
		return (nb * ft_recursive_factorial(nb - 1));
	else if ((nb == 0) || (nb == 1))
		return (1);
	else
		return (0);
}
