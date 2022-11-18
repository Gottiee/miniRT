/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:45:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/18 15:54:24 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

t_color	bckg(t_ray r)
{
	t_vec3		unit_vec;
    double		t;

	unit_vec = unit_vector(r.dir);
    t = 0.5 * (unit_vec.y + 1.0);
	return (plus(mult(new_vec(1, 1, 1), 1.0 - t), mult(new_vec(0.5, 0.7, 1), t)));	
}

t_color	ray_color(t_ray r, t_point light)
{
	t_record	rec;
	// t_vec3		light;
	double		level;

	if (hit_global(r, &rec, 0, DBL_MAX))
	{
		// light = unit_vector(new_vec(-1, -1, -1));
		level = dot(rec.normal, mult(light, -1));
		return (mult(new_vec(0.8, 0.4, 0.1), level));
	}
	// return (bckg(r));
	return (new_vec(0, 0, 0));
}

void	init_ray(t_ray *ray, t_cam cam, double u, double v)
{
	ray->orig = cam.origin;
	ray->dir = plus(cam.lower_left_corner, mult(cam.horizontal, u));
	ray->dir = plus(ray->dir, mult(cam.vertical, v));
	min_equal(&ray->dir, &cam.origin);
}

int render(t_data *data)
{
	t_vec2	c;
	t_ray	r;
	double	u;
	double	v;

	c.y = WINDOW_H - 1;
	while (c.y >= 0)
	{	
		c.x = 0;
		while (c.x < WINDOW_W)
		{
			u = (double)c.x / (WINDOW_W - 1);
			v = (double)c.y / (WINDOW_H - 1);
			init_ray(&r, data->cam, u, v);
			img_pix_put(&data->i, c.x, WINDOW_H - c.y, hexa(ray_color(r, data->cam.light)));
			c.x++;
		}
		c.y --;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->i.i, 0, 0);
	return (0);
}
