/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 02:23:41 by brel-baz          #+#    #+#             */
/*   Updated: 2017/04/16 03:37:00 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"

typedef struct      s_draw
{
    int dx;
    int sx;
    int dy;
    int sy;
    int err;
    int e2;
    void *mlx;
    void *win;
}                   t_draw;

typedef struct      s_point
{
    int x;
    int y;
}                   t_point;
