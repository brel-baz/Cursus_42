/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 02:05:25 by brel-baz          #+#    #+#             */
/*   Updated: 2017/04/05 00:27:18 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int	parse(char *file);

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_putnbr(parse(av[1]));
	else
		exit(1);
	return (0);
}
