/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:45:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/15 16:16:51 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

t_color *ray_color(t_ray r)
{
	t_color	*color;
	t_color	color2;
	double	t;
	
	color = malloc(sizeof(t_color));
	div_equal(&r.dir, length(&r.dir));
	t = 0.5 * (r.dir.e[1] + 1);
	color->e[0] = 1.0;
	color->e[1] = 1.0;
	color->e[2] = 1.0;
	mult_equal(color, 1.0 - t);
	color2.e[0] = 0.5;
	color2.e[1] = 0.7;
	color2.e[2] = 1.0;
	mult_equal(&color2, t);
	plus_equal(color, &color2);
	return (color);
}

t_ray	*get_ray(t_cam cam, double u, double v)
{
	t_ray	*new;
	
	new = malloc(sizeof(t_ray));
	new->orig = *cam.origin;
	new->dir = *cam.lower_left_corner;
	mult_const(cam.horizontal, u);
	mult_const(cam.vertical, v);
	plus_equal(&new->dir, cam.horizontal);
	plus_equal(&new->dir, cam.vertical);
	min_equal(&new->dir, cam.origin);
	return (new);
}

int render(t_data *data)
{
	int		i;
	int		j;
	t_cam	*cam;
	double	u;
	double	v;
	t_ray	*r;
	t_color	*color;

	cam = &data->cam;
	j = WINDOW_H - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WINDOW_W)
		{
			u = (double)i / (WINDOW_W - 1);
			v = (double)j / (WINDOW_H - 1);
			r = get_ray(*cam, u, v);
			color = ray_color(*r);
			free(r);
			img_pix_put(&data->i, i, j, hexa(*color));
			free(color);
			i++;
		}
		j --;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->i.i, 0, 0);
	return (0);
}