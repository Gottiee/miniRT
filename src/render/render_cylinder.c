/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/14 18:35:28 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	caps(t_cyl *c, t_vec3 dir_pix, t_vec3 cam_o, t_vec3 *rslt)
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
	DBL_MAX && get_rad(&base_rslt, base.center, c->radius) \
	&& dot(dir_pix, c->orient) > 0)
	{
		*rslt = base_rslt;
		return (c->inter_code = 2, var.t1);
	}
	if (var.t2 && (!var.t1 || var.t2 < var.t1) && var.t2 != \
	DBL_MAX && get_rad(&end_rslt, end.center, c->radius) \
	&& dot(dir_pix, c->orient) < 0)
	{
		*rslt = end_rslt;
		return (c->inter_code = 3, var.t2);
	}
	return (0);
}

double	exter_cyl(t_vec3 dir_pix, t_vec3 cam_o, t_cyl *c, t_vec3 *rslt)
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

double	get_cyl_t(t_vec3 dir_pix, t_vec3 cam_o, void *cylindre, t_vec3 *rslt)
{
	t_cyl		*cl;
	double		h;
	double		t;
	double		capst;
	t_vec3		rslt_caps;

	cl = (t_cyl *)cylindre;
	t = exter_cyl(dir_pix, cam_o, cl, rslt);
	capst = caps(cl, dir_pix, cam_o, &rslt_caps);
	if (capst && capst < t)
		return (*rslt = rslt_caps, capst);
	if (t)
	{
		h = norme(minus(*rslt, cl->center));
		h = sqrtf((h * h) - (cl->radius * cl->radius));
	}
	if (t && h < cl->height && dot(minus(*rslt, cl->center), cl->orient) > 0)
	{
		cl->inter_code = 1;
		return (t);
	}
	return (*rslt = rslt_caps, capst);
}

int	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	t_vec3		rslt;
	t_cyl		*c;

	(void)light;
	(void)limit;
	c = (t_cyl *)rec->closest;
	rec->t = get_cyl_t(r.dir, r.orig, c, &rslt);
	if (rec->t <= 0)
		return (0);
	rec->hit_point = at(r, rec->t);
	rec->normal = normal_cy(c, rec->hit_point, r.orig);
	rec->color = c->color;
	rec->light_level = 1;
	rec->type = CY;
	return (1);
}
