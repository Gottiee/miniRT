/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/15 13:25:24 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	degrees_to_radians(double degrees)
{
	return (degrees * M_PI / 180.0);
}

void	set_llc(t_cam *cam, t_vec3 w)
{
	cam->lower_left_corner = cam->origin;
	cam->lower_left_corner = minus(cam->lower_left_corner,
			divis(cam->horizontal, 2));
	cam->lower_left_corner = minus(cam->lower_left_corner,
			divis(cam->vertical, 2));
	cam->lower_left_corner = minus(cam->lower_left_corner, w);
}

void	update_cam(t_cam cam)
{
	t_lex	lex;

	lex.fov = cam.fov;
	lex.orient = divis(cam.lookat, 10);
	lex.coord = cam.lookfrom;
	init_cam(lex);
}

void	init_cam(t_lex lex)
{
	t_cam		*cam;

	cam = get_cam();
	cam->ratio = (double)WINDOW_W / WINDOW_H;
	cam->fov = lex.fov;
	cam->theta = degrees_to_radians(cam->fov);
	cam->h = tan(cam->theta / 2);
	cam->view_height = 2.0 * cam->h;
	cam->view_width = cam->ratio * cam->view_height;
	cam->lookfrom = lex.coord;
	cam->lookat = mult(lex.orient, 10);
	if (!cam->lookat.z)
		cam->lookat.z = -0.1;
	cam->vup = new_vec(0, 1, 0);
	cam->w = unit_vector(minus(cam->lookfrom, cam->lookat));
	cam->u = unit_vector(cross(cam->vup, cam->w));
	cam->v = cross(cam->w, cam->u);
	cam->focal = 2.0;
	cam->origin = cam->lookfrom;
	cam->horizontal = mult(cam->u, cam->view_width);
	cam->vertical = mult(cam->v, cam->view_height);
	set_llc(cam, cam->w);
}
