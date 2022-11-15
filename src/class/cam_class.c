/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/15 14:56:20 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_cam(t_cam *cam)
{
	cam->aspect_ratio = 16.0 / 9.0;
	cam->image_width = 400;
	cam->image_height = (int)(cam->image_width / cam->aspect_ratio);
	// cam->image_height = 1080;
	cam->viewport_height = 2.0;
	cam->viewport_width = cam->aspect_ratio * cam->viewport_height;
	cam->focal_length = 1.0;
	cam->origin = new_vec(0, 0, 0);
	cam->horizontal = new_vec(cam->viewport_width, 0, 0);
	cam->vertical = new_vec(0, cam->viewport_height, 0);
	cam->lower_left_corner = minus(minus(minus(cam->origin, div_const(cam->horizontal, 2)),
			div_const(cam->vertical, 2)), new_vec(0, 0, cam->focal_length));
}