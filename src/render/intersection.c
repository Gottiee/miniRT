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

double	inter_light(t_vec3 dir_pix, t_vec3 cam_o, void *sphere, t_vec3 *rslt)
{
	t_vec3	oc;
	t_eqn	inter;
	t_light	*sp;

	sp = (t_light *)sphere;
	eq_vector(&oc, minus(cam_o, *sp->center));
	eq_vector(&dir_pix, normalize(dir_pix));
	inter.b = scalaire_product(dir_pix, oc) * 2;
	inter.c = (scalaire_product(oc, oc) - (sp->radius * sp->radius));
	inter.delta = (inter.b * inter.b) - (4 * inter.c);
	if (inter.delta >= 0)
	{
		inter.t1 = ((inter.b * -1) - sqrtf(inter.delta)) / 2;
		inter.t2 = ((inter.b * -1) + sqrtf(inter.delta)) / 2;
		if (inter.t2 < 0)
			return (0);
		if (inter.t1 > 0)
			inter.t = inter.t1;
		else
			inter.t = inter.t2;
		eq_vector(rslt, plus(cam_o, mult(dir_pix, inter.t)));
	}
	else
		return (0);
	return (inter.t);
}

double	inter_sphere(t_vec3 dir_pix, t_vec3 cam_o, void *sphere, t_vec3 *rslt)
{
	t_vec3	oc;
	t_eqn	inter;
	t_sphere	*sp;

	sp = (t_sphere *)sphere;
	eq_vector(&oc, minus(cam_o, sp->center));
	eq_vector(&dir_pix, normalize(dir_pix));
	inter.b = scalaire_product(dir_pix, oc) * 2;
	inter.c = (scalaire_product(oc, oc) - (sp->radius * sp->radius));
	inter.delta = (inter.b * inter.b) - (4 * inter.c);
	if (inter.delta >= 0)
	{
		inter.t1 = ((inter.b * -1) - sqrtf(inter.delta)) / 2;
		inter.t2 = ((inter.b * -1) + sqrtf(inter.delta)) / 2;
		if (inter.t2 < 0)
			return (0);
		if (inter.t1 > 0)
			inter.t = inter.t1;
		else
			inter.t = inter.t2;
		eq_vector(rslt, plus(cam_o, mult(dir_pix, inter.t)));
	}
	else
		return (0);
	return (inter.t);
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

double	inter_ext_cl(t_vec3 dir_pix, t_vec3 cam_o, t_cyl *cl, t_vec3 *rslt)
{
	t_eqn	var;
	t_vec3	va;
	t_vec3	rao;

	eq_vector(&dir_pix, normalize(dir_pix));
	eq_vector(&cl->orient, normalize(cl->orient));
	eq_vector(&va, cross(cross(cl->orient, dir_pix), cl->orient));
	eq_vector(&rao, cross(cross(cl->orient, \
	minus(cam_o, cl->center)), cl->orient));
	var.a = scalaire_product(va, va);
	var.b = 2 * scalaire_product(rao, va);
	var.c = scalaire_product(rao, rao) - (cl->radius * cl->radius);
	var.delta = var.b * var.b - 4 * var.a * var.c;
	if (var.delta >= 0)
	{
		var.t1 = ((var.b * -1) - sqrtf(var.delta)) / (2 * var.a);
		var.t2 = ((var.b * -1) + sqrtf(var.delta)) / (2 * var.a);
		if (var.t2 < 0)
			return (0);
		var.t = (var.t1 > 0) * var.t1 + (var.t2 > 0 && var.t1 <= 0) * var.t2;
		eq_vector(rslt, plus(cam_o, mult(dir_pix, var.t)));
		return (var.t);
	}
	else
		return (0);
}

double	inter_circle_cl(t_cyl *cl, t_vec3 dir_pix, t_vec3 cam_o, t_vec3 *rslt)
{
	t_eqn	var;
	t_plane		base;
	t_plane		end;
	t_vec3	base_rslt;
	t_vec3	end_rslt;

	init_plan(&base, cl, -1);
	init_plan(&end, cl, 1);
	var.t1 = inter_plan(dir_pix, cam_o, &base, &base_rslt);
	var.t2 = inter_plan(dir_pix, cam_o, &end, &end_rslt);
	if (var.t1 && (!var.t2 || var.t1 < var.t2) && var.t1 != \
	FLT_MAX && into_radius(&base_rslt, base.center, cl->radius))
	{
		eq_vector(rslt, base_rslt);
		cl->inter_code = 2;
		return (var.t1);
	}
	if (var.t2 && (!var.t1 || var.t2 < var.t1) && var.t2 != \
	FLT_MAX && into_radius(&end_rslt, end.center, cl->radius))
	{
		eq_vector(rslt, end_rslt);
		cl->inter_code = 3;
		return (var.t2);
	}
	return (0);
}

double	inter_cylindre(t_vec3 dir_pix, t_vec3 cam_o, void *cylindre, t_vec3 *rslt)
{
	t_cyl	*cl;
	double		hyp;
	double		h;
	double		t;

	cl = (t_cyl *)cylindre;
	t = inter_ext_cl(dir_pix, cam_o, cl, rslt);
	if (t)
	{
		hyp = norme(minus(*rslt, cl->center));
		h = sqrtf((hyp * hyp) - (cl->radius * cl->radius));
	}
	if (t && h < cl->height && scalaire_product(minus(*rslt, cl->center), \
	cl->orient) > 0)
	{
		cl->inter_code = 1;
		return (t);
	}
	return (inter_circle_cl(cl, dir_pix, cam_o, rslt));
}
