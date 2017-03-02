/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:53:36 by brel-baz          #+#    #+#             */
/*   Updated: 2016/11/03 15:35:50 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int res;

	i = 1;
	res = 1;
	if ((nb >= 2) && (nb <= 12))
	{
		while (i <= nb)
		{
			res = res * i;
			i++;
		}
		return (res);
	}
	else if ((nb == 0) || (nb == 1))
		return (1);
	else
		return (0);
}
