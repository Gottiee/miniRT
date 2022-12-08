/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/08 14:54:12 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double degrees_to_radians(double degrees)
{
    return (degrees * M_PI / 180.0);
}

// void	set_llc(t_cam *cam, double fov)
// {	
// 	// lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
// 	cam->lower_left_corner = cam->origin;
// 	cam->lower_left_corner = minus(cam->lower_left_corner,
// 				divis(cam->horizontal, 2));
// 	cam->lower_left_corner = minus(cam->lower_left_corner,
// 				divis(cam->vertical, 2));
// 	cam->lower_left_corner = minus(cam->lower_left_corner, new_vec(0, 0, fov));
// }

			//        ray get_ray(double s, double t) const {
            // return ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);

void	set_llc(t_cam *cam, t_vec3 w)
{
	// lower_left_corner = origin - horizontal/2 - vertical/2 - w;
	cam->lower_left_corner = cam->origin;
	cam->lower_left_corner = minus(cam->lower_left_corner, divis(cam->horizontal, 2));
	cam->lower_left_corner = minus(cam->lower_left_corner, divis(cam->vertical, 2));
	cam->lower_left_corner = minus(cam->lower_left_corner, w);
	
}

void	update_cam(t_cam cam)
{
	t_lex	lex;

	lex.fov = cam.fov;
	lex.orient = cam.lookat;
	lex.coord = cam.lookfrom;
	init_cam(lex);
}

void	init_cam(t_lex lex)
{
	double		view_width;
	double		view_height;
	t_cam		*cam;
	double		ratio;
	double		theta;
	double		h;
	t_vec3		vup;		
    t_vec3		w;
    t_vec3		u;
    t_vec3		v;
	// t_matrix	rotate;
	
	cam = get_cam();
	ratio = (double)WINDOW_W / WINDOW_H;
	cam->fov = lex.fov;
	theta = degrees_to_radians(cam->fov);
	h = tan(theta / 2);
	view_height = 2.0 * h;
	view_width = ratio * view_height;
	

	// rotate = get_transfo_matrix(lex.coord, lex.orient);
	
	cam->lookfrom = lex.coord;
	cam->lookat = lex.orient;
	// cam->lookat = vector_x_matrix(cam->lookfrom, rotate, 1);
	// printv(cam->lookat);
	vup = new_vec(0, 1, 0);
	w = unit_vector(minus(cam->lookfrom, cam->lookat));
	u = unit_vector(cross(vup, w));
	v = cross(w, u);
	cam->focal = 2.0;
	cam->origin = cam->lookfrom;
	cam->horizontal = mult(u, view_width);
	cam->vertical = mult(v, view_height);
	set_llc(cam, w);
}
