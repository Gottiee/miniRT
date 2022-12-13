/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:54:32 by slahlou           #+#    #+#             */
/*   Updated: 2022/12/13 11:43:14 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec3	normal_sp(t_sphere *sp, t_vec3 hit_point, t_vec3 cam_pos)
{
	t_vec3	n_hit;

	eq_vector(&n_hit, normalize(minus(hit_point, sp->center)));
	if (norme(minus(cam_pos, sp->center)) < sp->radius)
		eq_vector(&n_hit, mult(n_hit, -1));
	return (n_hit);
}

double	inter_light(t_vec3 dir_pix, t_vec3 cam_o, void *sphere, t_vec3 *rslt)
{
	t_vec3	oc;
	t_eqn	eqn;
	t_light	*sp;

	sp = (t_light *)sphere;
	oc = minus(cam_o, *sp->center);
	dir_pix = normalize(dir_pix);
	eqn.b = dot(dir_pix, oc) * 2;
	eqn.c = (dot(oc, oc) - (sp->radius * sp->radius));
	eqn.delta = (eqn.b * eqn.b) - (4 * eqn.c);
	if (eqn.delta >= 0)
	{
		eqn.t1 = ((eqn.b * -1) - sqrtf(eqn.delta)) / 2;
		eqn.t2 = ((eqn.b * -1) + sqrtf(eqn.delta)) / 2;
		if (eqn.t2 < 0)
			return (0);
		if (eqn.t1 > 0)
			eqn.t = eqn.t1;
		else
			eqn.t = eqn.t2;
		*rslt = plus(cam_o, mult(dir_pix, eqn.t));
	}
	else
		return (0);
	return (eqn.t);
}

double	inter_sphere(t_vec3 dir_pix, t_vec3 cam_o, void *sphere, t_vec3 *rslt)
{
	t_vec3		oc;
	t_eqn		eqn;
	t_sphere	*sp;

	sp = (t_sphere *)sphere;
	oc = minus(cam_o, sp->center);
	dir_pix = normalize(dir_pix);
	eqn.b = dot(dir_pix, oc) * 2;
	eqn.c = (dot(oc, oc) - (sp->radius * sp->radius));
	eqn.delta = (eqn.b * eqn.b) - (4 * eqn.c);
	if (eqn.delta >= 0)
	{
		eqn.t1 = ((eqn.b * -1) - sqrtf(eqn.delta)) / 2;
		eqn.t2 = ((eqn.b * -1) + sqrtf(eqn.delta)) / 2;
		if (eqn.t2 < 0)
			return (0);
		if (eqn.t1 > 0)
			eqn.t = eqn.t1;
		else
			eqn.t = eqn.t2;
		*rslt = plus(cam_o, mult(dir_pix, eqn.t));
	}
	else
		return (0);
	return (eqn.t);
}
