/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:54:32 by slahlou           #+#    #+#             */
/*   Updated: 2022/12/13 12:31:57 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec3	normal_pl(t_plane *pl, t_vec3 hit_point, t_vec3 cam_pos)
{
	t_vec3	n_hit;

	eq_vector(&n_hit, normalize(pl->orient));
	if (dot(normalize(minus(hit_point, cam_pos)), n_hit) > 0)
		eq_vector(&n_hit, mult(n_hit, -1));
	return (n_hit);
}

double	inter_plan(t_vec3 dir_pix, t_vec3 cam_o, void *plan, t_vec3 *rslt)
{
	t_plane		*pl;
	t_vec3		norm;
	double		d;
	double		t;

	t = 0;
	d = 0;
	pl = (t_plane *)plan;
	norm = normalize(pl->orient);
	d = ((pl->center.x * norm.x) + (pl->center.y * norm.y) + \
	(pl->center.z * norm.z)) * -1;
	if (dot(norm, dir_pix))
		t = -1 * ((dot(norm, cam_o) + d) / (dot(norm, dir_pix)));
	*rslt = plus(cam_o, mult(dir_pix, t));
	return ((t > 0) * t);
}
