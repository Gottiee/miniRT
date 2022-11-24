/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:11:01 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/20 16:16:30 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

#define ABS(_x) ((_x) >= 0 ? (_x) : -(_x))
#define SGN(_x) ((_x) < 0 ? -1 : ((_x) > 0 ? 1 : 0))

void	horizontal_line(t_data *data, t_draw draw)
{
	for (int x = draw.x0; x != draw.x1 + draw.incX; x += draw.incX)
		display(data, x, draw.y0, 0xff0000);
}

void	vertical_line(t_data *data, t_draw draw)
{
	for (int y = draw.y0; y != draw.y1 + draw.incY; y += draw.incY)
		display(data, draw.x0, y, 0xff0000);
}

void more_horizontal(t_data *data, t_draw draw)
{
	int slope;
	int error;
	int error_inc;
	int y;
	int x;
	
	x = draw.x0;
	slope = 2 * draw.dy;
	error = -draw.dx;
	error_inc = -2 * draw.dx;
	y = draw.y0;
	while (x != draw.x1 + draw.incX)
	{
		display(data, x, y, 0xff0000);
		error += slope;
		if (error >= 0)
		{
			y += draw.incY;
			error += error_inc;
		}
		x += draw.incX;
	}
}

void more_vertical(t_data *data, t_draw draw)
{
	int slope;
	int error;
	int error_inc;
	int x;
	int	y;
	
	y = draw.y0;
	slope = 2 * draw.dx;
	error = -draw.dy;
	error_inc = -2 * draw.dy;
	x = draw.x0;
	while (y != draw.y1)
	{
		display(data, x, y, 0xff0000);
		error += slope;
		if (error >= 0)
		{
			x += draw.incX;
			error += error_inc;
		}
		y += draw.incY;
	}
}

void draw_line(t_data *data, int x0, int y0, int x1, int y1)
{
	t_draw	draw;
	
	draw.dx = x1 - x0;
	draw.dy = y1 - y0;
	draw.incX = SGN(draw.dx);
	draw.incY = SGN(draw.dy);
	draw.dx = ABS(draw.dx);
	draw.dy = ABS(draw.dy);
	draw.x0 = x0;
	draw.y0 = y0;
	draw.x1 = x1;
	draw.y1 = y1;
	if (draw.dy == 0)
		horizontal_line(data, draw);
	else if (draw.dx == 0)
		vertical_line(data, draw);
	else if (draw.dx >= draw.dy)
		more_horizontal(data, draw);
	else
		more_vertical(data, draw);
}
