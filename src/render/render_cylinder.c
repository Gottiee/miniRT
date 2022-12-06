/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/06 18:09:42 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	into_radius(t_vec3 *rslt, t_vec3 base, double radius)
{
	if ((radius + 0.012) - norme(minus(base, *rslt)) <= 0)
		return (0);
	return (1);
}

double	inter_plan(t_vec3 dir_pix, t_vec3 cam_o, void *plan, t_vec3 *rslt)
{
	t_plan		*pl;
	double		d;
	double		t;
	t_vec3	pl_normal;

	t = 0;
	d = 0;
	pl = (t_plan *)plan;
	eq_vector(&pl_normal, normalize(pl->normal_vec));
	d = ((pl->center.x * pl_normal.x) + (pl->center.y * pl_normal.y) + \
	(pl->center.z * pl_normal.z)) * -1;
	if (dot(pl_normal, dir_pix))
		t = -1 * ((dot(pl_normal, cam_o) + d) / \
		(dot(pl_normal, dir_pix)));
	eq_vector(rslt, plus(cam_o, mult(dir_pix, t)));
	return ((t > 0) * t);
}

void	new_plane(t_plane *plan, t_cyl *c, double normal)
{
	if (normal == -1)
		eq_vector(&plan->center, c->center);
	else
		eq_vector(&plan->center, plus(c->center, \
		mult(normalize(c->orient), c->heigth)));
	eq_vector(&plan->orient, \
	mult(normalize(c->orient), normal));
	eq_vector(&plan->color, c->color);
}

double	cyl_caps(t_cylindre *c, t_vec3 dir_pix, t_vec3 cam_o, t_vec3 *rslt)
{
	t_equation	var;
	t_plane		base;
	t_plane		end;
	t_vec3	base_rslt;
	t_vec3	end_rslt;

	new_plane(&base, c, -1);
	new_plane(&end, c, 1);
	var.t1 = inter_plan(dir_pix, cam_o, &base, &base_rslt);
	var.t2 = inter_plan(dir_pix, cam_o, &end, &end_rslt);
	if (var.t1 && (!var.t2 || var.t1 < var.t2) && var.t1 != \
	DBL_MAX && into_radius(&base_rslt, base.center, c->radius))
	{
		eq_vector(rslt, base_rslt);
		c->inter_code = 2;
		return (var.t1);
	}
	if (var.t2 && (!var.t1 || var.t2 < var.t1) && var.t2 != \
	DBL_MAX && into_radius(&end_rslt, end.center, c->radius))
	{
		eq_vector(rslt, end_rslt);
		c->inter_code = 3;
		return (var.t2);
	}
	return (0);
}

double	cyl_side(t_vec3 dir_pix, t_vec3 cam_o, t_cylindre *c, t_vec3 *rslt)
{
	t_eqn	eqn;
	t_vec3	va;
	t_vec3	rao;

	eq_vector(&dir_pix, normalize(dir_pix));
	eq_vector(&c->orient, normalize(c->orient));
	eq_vector(&va, cross(cross(c->orient, dir_pix), c->orient));
	eq_vector(&rao, cross(cross(c->orient, \
	minus(cam_o, c->center)), c->orient));
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
		eq_vector(rslt, plus(cam_o, mult(dir_pix, eqn.t)));
		return (eqn.t);
	}
	else
		return (0);
}

double	get_cyl_t(t_record *rec, t_ray r, t_cyl *c, t_vec3 *rslt)
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
	if (t && h < c->heigth && dot(minus(*rslt, c->center), c->dir) > 0)
	{
		c->inter_code = 1;
		return (t);
	}
	return (cyl_caps(c, r.dir, r.orig, rslt));
}

double	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	t_vec3		rslt;
	t_cyl		*c;

	c = (t_cyl *)rec->closest;
	rec->t = get_cyl_t(rec, r, c, rslt);
	if (!rec->t)
		return (0);
	rec->hit_point = rslt;
	rec->normal = normal_cy(c, rec->hit_point, r.orig);
	rec->color = c->color;
	rec->light_level = 1;
}
