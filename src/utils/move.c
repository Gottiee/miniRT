/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:34:58 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/07 14:50:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	move(int keysym, t_data *data)
{
	t_cam	*cam;

	cam = get_cam();
	if (keysym == XK_a)
		cam->lookfrom = (plus(cam->lookfrom, new_vec(-0.1, 0, 0)));
	if (keysym == XK_d)
		cam->lookfrom = (plus(cam->lookfrom, new_vec(0.1, 0, 0)));
	if (keysym == XK_s)
		cam->lookfrom = (plus(cam->lookfrom, new_vec(0, -0.1, 0)));
	if (keysym == XK_w)
		cam->lookfrom = (plus(cam->lookfrom, new_vec(0, 0.1, 0)));
	if (keysym == XK_q)
		cam->lookfrom = (plus(cam->lookfrom, new_vec(0, 0, 0.1)));
	if (keysym == XK_e)
		cam->lookfrom = (plus(cam->lookfrom, new_vec(0, 0, -0.1)));
	if (keysym == XK_k)
		data->light = plus(data->light, new_vec(0, -0.1, 0));
	if (keysym == XK_l)
		data->light = plus(data->light, new_vec(0.1, 0, 0));
	if (keysym == XK_i)
		data->light = plus(data->light, new_vec(0, 0.1, 0));
	if (keysym == XK_j)
		data->light = plus(data->light, new_vec(-0.1, 0, 0));
	if (keysym == XK_o)
		data->light = plus(data->light, new_vec(0, 0, -0.1));
	if (keysym == XK_u)
		data->light = plus(data->light, new_vec(0, 0, 0.1));
	if (keysym == XK_Up)
		cam->lookat = unit_vector(plus(cam->lookat, new_vec(0, -0.1, 0)));
	if (keysym == XK_Down)
		cam->lookat = unit_vector(plus(cam->lookat, new_vec(0, 0.1, 0)));
	if (keysym == XK_Right)
		cam->lookat = unit_vector(plus(cam->lookat, new_vec(-0.1, 0, 0)));
	if (keysym == XK_Left)
		cam->lookat = unit_vector(plus(cam->lookat, new_vec(0.1, 0, 0)));
	if (keysym == XK_z)
		cam->lookat = unit_vector(plus(cam->lookat, new_vec(0, 0, 0.1)));
	if (keysym == XK_x)
		cam->lookat = unit_vector(plus(cam->lookat, new_vec(0, 0, -0.1)));
	if (keysym == XK_n)
		data->disp_normals = data->disp_normals == 0;		
	data->render_image = 1;
}

int	key_release(int keysym, t_data *data)
{
	if (data->left == 2)
		data->left = 0;
	if (data->right == 2)
		data->right = 0;
	if (data->down == 2)
		data->down = 0;
	if (data->up == 2)
		data->up = 0;
	if (data->far == 2)
		data->far = 0;
	if (data->close == 2)
		data->close = 0;
	if (keysym == XK_Up)
		data->up = 2;
	else if (keysym == XK_Down)
		data->down = 2;
	else if (keysym == XK_Left)
		data->left = 2;
	else if (keysym == XK_Right)
		data->right = 2;
	else if (keysym == XK_w)
		data->far = 2;
	else if (keysym == XK_s)
		data->close = 2;
	return (1);
}

void	init_move(t_data *data)
{
	data->up = 0;
	data->down = 0;
	data->left = 0;
	data->right = 0;
	data->far = 0;
	data->close = 0;
	data->disp_normals = 0;
}
