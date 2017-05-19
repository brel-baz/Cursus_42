/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 05:27:30 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/11 05:27:34 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(t_draw *dw)
{
	dw->k = 0;
	dw->tab_color[0] = 0xFFFFFF;
	dw->tab_color[1] = 0xDB1702;
	dw->tab_color[2] = 0xF7FF3C;
	dw->tab_color[3] = 0x096A09;
	dw->tab_color[4] = 0xFD6C9E;
	dw->tab_color[5] = 0x01B0F0;
	dw->tab_color[6] = 0xAD4F09;
	dw->tab_color[7] = 0x606060;
	dw->tab_color[8] = 0x791CF8;
	dw->tab_color[9] = 0xEFD807;
	dw->tab_color[10] = 0xAE8964;
}
