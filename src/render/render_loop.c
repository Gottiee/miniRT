/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:45:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/14 17:58:34 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_color	bckg(t_ray r)
{
	t_vec3	unit_vec;
	double	t;

	unit_vec = unit_vector(r.dir);
	t = 0.5 * (unit_vec.y + 1.0);
	return (plus(mult(new_vec(1, 1, 1), 1.0 - t), \
	mult(new_vec(0.5, 0.7, 1), t)));
}

t_color	ray_color(t_ray r, t_point light, int normals)
{
	t_record	rec;

	if (hit_global(r, &rec, light))
	{
		if (rec.type != L)
			shadow_render(&rec, light);
		if (normals)
			return (mult(plus(rec.normal, new_vec(1, 1, 1)), 0.5));
		return (mult(rec.color, rec.light_level));
	}
	return (new_vec(0, 0, 0));
}

void	init_ray(t_ray *ray, t_cam cam, double u, double v)
{
	ray->orig = cam.origin;
	ray->dir = plus(cam.lower_left_corner, mult(cam.horizontal, u));
	ray->dir = plus(ray->dir, mult(cam.vertical, v));
	min_equal(&ray->dir, &cam.origin);
}

int	render(t_data *data)
{
	t_vec2	c;
	t_ray	r;
	double	u;
	double	v;
	t_cam	*cam;

	cam = get_cam();
	update_cam(*cam);
	c.y = WINDOW_H - 1;
	while (c.y >= 0)
	{
		c.x = 0;
		while (c.x < WINDOW_W)
		{
			u = c.x / (WINDOW_W - 1);
			v = c.y / (WINDOW_H - 1);
			init_ray(&r, *cam, u, v);
			img_pix_put(&data->i, c.x, WINDOW_H - c.y, \
			hexa(ray_color(r, data->light, data->disp_normals)));
			c.x++;
		}
		c.y --;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->i.i, 0, 0);
	return (0);
}
