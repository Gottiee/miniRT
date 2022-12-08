/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/08 18:09:53 by gmansuy          ###   ########.fr       */
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
	t_vec3	pl_normal;

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

double	cyl_caps(t_cyl *c, t_vec3 dir_pix, t_vec3 cam_o, t_vec3 *rslt)
{
	t_eqn		var;
	t_plane		base;
	t_plane		end;
	t_vec3		base_rslt;
	t_vec3		end_rslt;

	new_plane(&base, c, -1);
	new_plane(&end, c, 1);
	var.t1 = intersect_plan(dir_pix, cam_o, &base, &base_rslt);
	var.t2 = intersect_plan(dir_pix, cam_o, &end, &end_rslt);
	if (var.t1 && (!var.t2 || var.t1 < var.t2) && var.t1 != \
	DBL_MAX && get_rad(&base_rslt, base.center, c->radius))
	{
		*rslt = base_rslt;
		c->inter_code = 2;
		return (var.t1);
	}
	if (var.t2 && (!var.t1 || var.t2 < var.t1) && var.t2 != \
	DBL_MAX && get_rad(&end_rslt, end.center, c->radius))
	{
		*rslt = end_rslt;
		c->inter_code = 3;
		return (var.t2);
	}
	return (0);
}

double	cyl_side(t_vec3 dir_pix, t_vec3 cam_o, t_cyl *c, t_vec3 *rslt)
{
	t_eqn	eqn;
	t_vec3	va;
	t_vec3	rao;

	dir_pix = unit_vector(dir_pix);
	c->orient = unit_vector(c->orient);
	va = cross(cross(c->orient, dir_pix), c->orient);
	rao = cross(cross(c->orient, \
	minus(cam_o, c->center)), c->orient);
	eqn.a = dot(va, va);
	eqn.b = 2 * dot(rao, va);
	eqn.c = dot(rao, rao) - (c->radius * c->radius);
	eqn.delta = eqn.b * eqn.b - 4 * eqn.a * eqn.c;
	if (eqn.delta >= 0)
	{
		eqn.t1 = ((eqn.b * -1) - sqrtf(eqn.delta)) / (2 * eqn.a);
		eqn.t2 = ((eqn.b * -1) + sqrtf(eqn.delta)) / (2 * eqn.a);
		if (eqn.t2 < 0)
			return (0);
		eqn.t = (eqn.t1 > 0) * eqn.t1 + (eqn.t2 > 0 && eqn.t1 <= 0) * eqn.t2;
		*rslt = plus(cam_o, mult(dir_pix, eqn.t));
		return (eqn.t);
	}
	else
		return (0);
}

double	get_cyl_t(t_ray r, t_cyl *c, t_vec3 *rslt)
{
	double		hyp;
	double		h;
	double		t;

	t = cyl_side(r.dir, r.orig, c, rslt);
	if (t)
	{
		hyp = norme(minus(*rslt, c->center));
		h = sqrtf((hyp * hyp) - (c->radius * c->radius));
	}
	if (t && h < c->height && dot(minus(*rslt, c->center), c->orient) > 0)
	{
		c->inter_code = 1;
		return (t);
	}
	// return (0);
	return (cyl_caps(c, r.dir, r.orig, rslt));
}

int	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	t_vec3		rslt;
	t_cyl		*c;

	(void)light;
	(void)limit;
	c = (t_cyl *)rec->closest;
	rec->t = get_cyl_t(r, c, &rslt);
	if (!rec->t)
		return (0);
	if (rec->t < 0 || rec->t > limit.y)
		return (0);
	rec->hit_point = rslt;
	rec->normal = normal_cy(c, rec->hit_point, r.orig);
	rec->color = c->color;
	rec->light_level = 1;
	return (1);
}
