/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/15 13:31:05 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

t_color *ray_color(t_ray r)
{
	t_vec	*unit_direction;
	double	t;
	
	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction->e[1] + 1.0);
	return (plus(mult_const(new_vec(1, 1, 1), 1.0 - t),
		mult_const(new_vec(0.5, 0.7, 1), t)));
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
	(void)color;
	(void)r;
	cam = &(data->cam);
	j = cam->image_height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < cam->image_width)
		{
			u = (double)i / (cam->image_width - 1);
			v = (double)j / (cam->image_height - 1);
			r = init_ray(cam->origin, minus(plus(plus(cam->lower_left_corner,
				mult_const(cam->horizontal, u)), mult_const(cam->vertical, v)), cam->origin));
			color = ray_color(*r);
			img_pix_put(&data->i, i, j, hexa(*color));
			// img_pix_put(&data->i, i, j, 1);
			i++;
		}
		j --;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->i.i, 0, 0);
	return (0);
}

// int	render(t_data *data)
// {
// 	int color = 0xffffff;
	
// 	int	j;
// 	int	i;

// 	j = 0;
// 	while (j < 224)
// 	{
// 		i = 0;
// 		while (i < 400)
// 			img_pix_put(&data->i, i++, j, color);
// 		j ++;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->i.i, 0, 0);
// 	return (0);
// }

int	main()
{	
	mlx_center();
	return (0);
}