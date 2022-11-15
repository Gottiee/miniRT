/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:18:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/15 16:20:06 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec	*get_lower(t_cam *cam, t_vec horizontal, t_vec vertical)
{
	t_vec	*new;
	
	new = new_vec(0, 0, 0);
	div_equal(&horizontal, 2);
	div_equal(&vertical, 2);
	min_equal(new, &horizontal);
	min_equal(new, &vertical);
	new->e[2] -= cam->focal_length;
	return (new);
}

void	init_cam(t_cam *cam)
{
	cam->aspect_ratio = (double)WINDOW_W / (double)WINDOW_H;
	cam->viewport_height = 2.0;
	cam->viewport_width = cam->aspect_ratio * cam->viewport_height;
	cam->focal_length = 1.0;
	cam->origin = new_vec(0, 0, 0);
	cam->horizontal = new_vec(cam->viewport_width, 0, 0);
	cam->vertical = new_vec(0, cam->viewport_height, 0);
	cam->lower_left_corner = get_lower(cam, *cam->horizontal, *cam->vertical);
}