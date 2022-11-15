/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:45:32 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/15 19:03:31 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int	ray_color(t_ray r, t_color *color)
{
    t_color color2;
	t_point	p;
    double  t;

	vec(&p, 0, 0, -1);
	if (hit_sphere(&p, 0.5, r))
		return (0x0088ff);	
    div_equal(&r.dir, length(&r.dir));
    t = 0.5 * (r.dir.e[1] + 1);
    color->e[0] = 1.0;
    color->e[1] = 1.0;
    color->e[2] = 1.0;
    mult_equal(color, 1.0 - t);
    color2.e[0] = 1.0;
    color2.e[1] = 0.7;
    color2.e[2] = 0.5;
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
			img_pix_put(&data->i, i, j, ray_color(r, &color));
			// usleep(100000);
			i++;
		}
		j --;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->i.i, 0, 0);
	return (0);
}