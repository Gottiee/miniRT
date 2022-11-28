/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/28 12:29:59 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	set_llc(t_cam *cam, double focal)
{	
	// lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
	cam->lower_left_corner = cam->origin;
	cam->lower_left_corner = minus(cam->lower_left_corner,
				divis(cam->horizontal, 2));
	cam->lower_left_corner = minus(cam->lower_left_corner,
				divis(cam->vertical, 2));
	cam->lower_left_corner = minus(cam->lower_left_corner, new_vec(0, 0, focal));
	// cam->lower_left_corner = plus(cam->lower_left_corner, unit_vector(cam->rotate));
}

void	init_cam(t_cam *cam, double ratio, double view_height, double focal)
{
	double	view_width;

	view_width = ratio * view_height;

	cam->lookfrom = new_vec(0, 1, 0);
	cam->lookat = new_vec(0, 0, -1);
	cam->vup = new_vec(0, -1, 0);
	cam->w = unit_vector(minus(cam->lookfrom, cam->lookat));
	cam->u = unit_vector(cross(cam->vup, cam->w));
	cam->v = cross(cam->w, cam->u);

	cam->origin = cam->lookfrom;
	cam->horizontal = mult_vec(new_vec(view_width, 0, 0), cam->u);
	cam->vertical = mult_vec(new_vec(0, view_height, 0), cam->v);
	cam->lower_left_corner = minus(minus(minus(divis(cam->vertical, 2), cam->w), divis(cam->horizontal, 2)), cam->origin);
	cam->focal = focal;
	cam->rotate = new_vec(0, 0, 0);
	cam->light = mult(new_vec(-0.5, 0.7, -1.9), -1);

	// cam->light = unit_vector(mult(new_vec(1, 0, -0.5), -1));
}
