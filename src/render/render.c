/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:45:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/16 12:46:14 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int	ray_color(t_ray r, t_color *color)
{
    t_color color2;
	t_point	p;
    double  t;

	//p est la position de al sphere dans l'espace
	vec(&p, 0, 0, -1);
	t = hit_sphere(&p, 0.5, r);
	vec(color, 1, 1, 1);
	vec(&color2, 1, 0.7, 0.5);
	if (t > 0.0)
	{
		at(&r, t);
		min_equal(&r.orig, &p);
    	div_equal(&r.orig, length(&r.orig));
		plus_equal(color, &r.orig);
		mult_equal(color, 0.5);
		return (hexa(color));
	}
    div_equal(&r.dir, length(&r.dir));
    t = 0.5 * (r.dir.e[1] + 1);
	mult_equal(color, 1.0 - t);
    mult_equal(&color2, t);
    plus_equal(color, &color2);
	return (hexa(color));

}

void	get_ray(t_cam cam, double u, double v, t_ray *new)
{
	new->orig = *cam.origin;
	new->dir = *cam.lower_left_corner;
	cam.horizontal = mult_equal(&cam.horizontal, u);
	cam.vertical = mult_equal(&cam.vertical, v);
	new->dir = plus_equal(&new->dir, &cam.horizontal);
	new->dir = plus_equal(&new->dir, &cam.vertical);
	min_equal(&new->dir, cam.origin);
}

int render(t_data *data)
{
	int		i;
	int		j;
	t_ray	r;
	t_color	color;
	double	u;
	double	v;

	j = WINDOW_H - 1;
	while (j >= 0)
	{	
		i = 0;
		while (i < WINDOW_W)
		{
			u = (double)i / (WINDOW_W - 1);
			v = (double)j / (WINDOW_H - 1);
			get_ray(data->cam, u, v, &r);
			img_pix_put(&data->i, i, WINDOW_H - j, ray_color(r, &color));
			i++;
		}
		j --;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->i.i, 0, 0);
	return (0);
}
