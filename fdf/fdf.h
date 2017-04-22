/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brel-baz <brel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 02:23:41 by brel-baz          #+#    #+#             */
/*   Updated: 2017/04/16 05:30:34 by brel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include <stdio.h>
#include "mlx.h"
#define ZOOM 15

typedef struct      s_point
{
    double x;
    double y;
    double z;
    double w;
    double length;
    double width;
}                   t_point;

typedef struct      s_draw
{
    double dx;
    double sx;
    double dy;
    double sy;
    double err;
    double e2;
    double bpp;
    double size_line;
    double endian;
    void *mlx;
    void *win;
    void *image;
    char *ptr;
}                   t_draw;