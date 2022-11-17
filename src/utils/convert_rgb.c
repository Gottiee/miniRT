/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:55:11 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/17 12:21:33 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	hexa(t_color *col)
{
	int r;
	int g;
	int b;
	
	r = (int)(col->e[0] * 255);
	g = (int)(col->e[1] * 255);
	b = (int)(col->e[2] * 255);
	return (r << 16 | g << 8 | b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->a + (y * img->l + x * (img->b / 8));
	if (pixel)
		*(int *)pixel = color;
}
