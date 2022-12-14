/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/14 18:31:45 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	get_rad(t_vec3 *rslt, t_vec3 base, double radius)
{
	if ((radius + 0.012) - norme(minus(base, *rslt)) <= 0)
		return (0);
	return (1);
}

double	intersect_plan(t_vec3 dir_pix, t_vec3 cam_o, void *plan, t_vec3 *rslt)
{
	t_plane		*pl;
	double		d;
	double		t;
	t_vec3		pl_normal;

	t = 0;
	d = 0;
	pl = (t_plane *)plan;
	pl_normal = unit_vector(pl->orient);
	d = ((pl->center.x * pl_normal.x) + (pl->center.y * pl_normal.y) + \
	(pl->center.z * pl_normal.z)) * -1;
	if (dot(pl_normal, dir_pix))
		t = -1 * ((dot(pl_normal, cam_o) + d) / \
		(dot(pl_normal, dir_pix)));
	*rslt = plus(cam_o, mult(dir_pix, t));
	return ((t > 0) * t);
}

void	new_plane(t_plane *plan, t_cyl *c, double normal)
{
	if (normal == -1)
		plan->center = c->center;
	else
		plan->center = plus(c->center, \
		mult(unit_vector(c->orient), c->height));
	plan->orient = mult(unit_vector(c->orient), normal);
	plan->color = c->color;
}
