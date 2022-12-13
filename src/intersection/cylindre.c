/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:54:32 by slahlou           #+#    #+#             */
/*   Updated: 2022/12/13 15:25:25 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec3	get_cy_norm(t_cyl *cl, t_vec3 hit_point)
{
	t_vec3		b_phit;
	t_vec3		n_hit;
	double		hyp;
	double		h;

	eq_vector(&b_phit, minus(hit_point, cl->center));
	eq_vector(&cl->orient, normalize(cl->orient));
	hyp = norme(b_phit);
	h = sqrtf((hyp * hyp) - (cl->radius * cl->radius));
	if (cl->inter_code == 1)
		eq_vector(&n_hit, normalize(minus(hit_point, \
		plus(cl->center, mult(cl->orient, h)))));
	else if (cl->inter_code == 2)
		eq_vector(&n_hit, mult(cl->orient, -1));
	else
		eq_vector(&n_hit, cl->orient);
	return (n_hit);
}

t_vec3	normal_cy(t_cyl *cy, t_vec3 hit_point, t_vec3 cam_pos)
{
	t_vec3	n_hit;

	eq_vector(&n_hit, get_cy_norm(cy, hit_point));
	if (dot(normalize(minus(hit_point, cam_pos)), n_hit) > 0)
		eq_vector(&n_hit, mult(n_hit, -1));
	return (n_hit);
}

double	exter_cyl(t_vec3 dir_pix, t_vec3 cam_o, t_cyl *cl, t_vec3 *rslt)
{
	t_eqn	eqn;
	t_vec3	va;
	t_vec3	rao;

	eq_vector(&dir_pix, normalize(dir_pix));
	eq_vector(&cl->orient, normalize(cl->orient));
	eq_vector(&va, cross(cross(cl->orient, dir_pix), cl->orient));
	eq_vector(&rao, cross(cross(cl->orient, \
	minus(cam_o, cl->center)), cl->orient));
	eqn.a = dot(va, va);
	eqn.b = 2 * dot(rao, va);
	eqn.c = dot(rao, rao) - (cl->radius * cl->radius);
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

double	caps(t_cyl *cl, t_vec3 dir_pix, t_vec3 cam_o, t_vec3 *rslt)
{
	t_eqn		eqn;
	t_plane		base;
	t_plane		end;
	t_vec3		base_rslt;
	t_vec3		end_rslt;

	init_plan(&base, cl, -1);
	init_plan(&end, cl, 1);
	eqn.t1 = inter_plan(dir_pix, cam_o, &base, &base_rslt);
	eqn.t2 = inter_plan(dir_pix, cam_o, &end, &end_rslt);
	if (eqn.t1 && (!eqn.t2 || eqn.t1 < eqn.t2) && eqn.t1 != \
	FLT_MAX && into_radius(&base_rslt, base.center, cl->radius)
	&& dot(dir_pix, cl->orient) > 0)
	{
		eq_vector(rslt, base_rslt);
		cl->inter_code = 2;
		return (eqn.t1);
	}
	if (eqn.t2 && (!eqn.t1 || eqn.t2 < eqn.t1) && eqn.t2 != \
	FLT_MAX && into_radius(&end_rslt, end.center, cl->radius)
	&& dot(dir_pix, cl->orient) < 0)
	{
		eq_vector(rslt, end_rslt);
		cl->inter_code = 3;
		return (eqn.t2);
	}
	return (0);
}

double	inter_cylindre(t_vec3 dir_pix, t_vec3 cam_o, void *cylindre, t_vec3 *rslt)
{
	t_cyl		*cl;
	double		hyp;
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
		hyp = norme(minus(*rslt, cl->center));
		h = sqrtf((hyp * hyp) - (cl->radius * cl->radius));
	}
	if (t && h < cl->height && dot(minus(*rslt, cl->center), cl->orient) > 0)
	{
		cl->inter_code = 1;
		return (t);
	}
	return (*rslt = rslt_caps, capst);
}
