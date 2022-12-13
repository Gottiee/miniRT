/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:54:32 by slahlou           #+#    #+#             */
/*   Updated: 2022/12/12 23:16:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec3	normal_pl(t_plane *pl, t_vec3 hit_point, t_vec3 cam_pos)
{
	t_vec3	n_hit;

	eq_vector(&n_hit, normalize(pl->orient));
	if (scalaire_product(normalize(minus(hit_point, cam_pos)), n_hit) > 0)
		eq_vector(&n_hit, mult(n_hit, -1));
	return (n_hit);
}

double	inter_plan(t_vec3 dir_pix, t_vec3 cam_o, void *plan, t_vec3 *rslt)
{
	t_plane		*pl;
	double		d;
	double		t;
	t_vec3	pl_normal;

	t = 0;
	d = 0;
	pl = (t_plane *)plan;
	eq_vector(&pl_normal, normalize(pl->orient));
	d = ((pl->center.x * pl_normal.x) + (pl->center.y * pl_normal.y) + \
	(pl->center.z * pl_normal.z)) * -1;
	if (scalaire_product(pl_normal, dir_pix))
		t = -1 * ((scalaire_product(pl_normal, cam_o) + d) / \
		(scalaire_product(pl_normal, dir_pix)));
	eq_vector(rslt, plus(cam_o, mult(dir_pix, t)));
	return ((t > 0) * t);
}
