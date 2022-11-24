/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:55:11 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/24 11:48:23 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return min;
    if (x > max)
		return max;
    return (x);
}

int	hexa(t_color col)
{
	int r;
	int g;
	int b;
	
	col.x = clamp(col.x, 0, 1);
	col.y = clamp(col.y, 0, 1);
	col.z = clamp(col.z, 0, 1);
	r = (int)(col.x * 255);
	g = (int)(col.y * 255);
	b = (int)(col.z * 255);
	return (r << 16 | g << 8 | b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->a + (y * img->l + x * (img->b / 8));
	if (pixel)
		*(int *)pixel = color;
}
