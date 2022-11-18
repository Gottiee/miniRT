/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:34:58 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/18 15:54:21 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	move(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->cam.light = plus(data->cam.light, new_vec(0.1, 0, 0));
	if (keysym == XK_Right)
		data->cam.light = plus(data->cam.light, new_vec(-0.1, 0, 0));
	if (keysym == XK_Down)
		data->cam.light = plus(data->cam.light, new_vec(0, 0.1, 0));
	if (keysym == XK_Up)
		data->cam.light = plus(data->cam.light, new_vec(0, -0.1, 0));
}