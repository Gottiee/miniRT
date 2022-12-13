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
