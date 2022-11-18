/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/18 17:01:04 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_cam(t_cam *cam, double ratio, double view_height, double focal)
{
	double	view_width;

	view_width = ratio * view_height;
	cam->origin = new_vec(0, 0, 0);
	cam->horizontal = new_vec(view_width, 0, 0);
	cam->vertical = new_vec(0, view_height, 0);
	// lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
	cam->lower_left_corner = cam->origin;
	cam->lower_left_corner = minus(cam->lower_left_corner,
				divis(cam->horizontal, 2));
	cam->lower_left_corner = minus(cam->lower_left_corner,
				divis(cam->vertical, 2));
	cam->lower_left_corner = minus(cam->lower_left_corner, new_vec(0, 0, focal));
	cam->light = unit_vector(new_vec(-1, -1, -1));
}