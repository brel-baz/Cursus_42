/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:16:37 by brel-baz          #+#    #+#             */
/*   Updated: 2017/05/06 10:16:40 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_up(t_draw *dw)
{
	dw->i = 0;
	while (dw->i < dw->length)
	{
		dw->j = 0;
		while (dw->j < dw->width)
		{
			dw->tab3[dw->i][dw->j].x *= 2;
			dw->tab3[dw->i][dw->j].y *= 2;
			dw->tab3[dw->i][dw->j].z *= 2;
			dw->j++;
		}
		dw->i++;
	}
}

void	zoom_less(t_draw *dw)
{
	dw->i = 0;
	while (dw->i < dw->length)
	{
		dw->j = 0;
		while (dw->j < dw->width)
		{
			dw->tab3[dw->i][dw->j].x /= 2;
			dw->tab3[dw->i][dw->j].y /= 2;
			dw->tab3[dw->i][dw->j].z /= 2;
			dw->j++;
		}
		dw->i++;
	}
}

void	tr_right(t_draw *dw)
{
	dw->i = 0;
	while (dw->i < dw->length)
	{
		dw->j = 0;
		while (dw->j < dw->width)
		{
			dw->tab3[dw->i][dw->j].x += 2;
			dw->tab3[dw->i][dw->j].y += 2;
			dw->tab3[dw->i][dw->j].z += 2;
			dw->j++;
		}
		dw->i++;
	}
}

void	tr_left(t_draw *dw)
{
	dw->i = 0;
	while (dw->i < dw->length)
	{
		dw->j = 0;
		while (dw->j < dw->width)
		{
			dw->tab3[dw->i][dw->j].x -= 2;
			dw->tab3[dw->i][dw->j].y -= 2;
			dw->tab3[dw->i][dw->j].z -= 2;
			dw->j++;
		}
		dw->i++;
	}
}
