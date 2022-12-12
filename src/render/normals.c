/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:16:53 by slahlou           #+#    #+#             */
/*   Updated: 2022/12/12 21:32:41 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"


t_vec3	get_nhit_cl(t_cyl *cl, t_vec3 hit_point)
{
	t_vec3	b_phit;
	t_vec3	n_hit;
	float		hyp;
	float		h;

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

t_vec3	compute_nhit_cy(t_cyl *cy, t_vec3 hit_point, t_vec3 cam_pos)
{
	t_vec3	n_hit;

	eq_vector(&n_hit, get_nhit_cl(cy, hit_point));
	if (scalaire_product(normalize(minus(hit_point, cam_pos)), n_hit) > 0)
		eq_vector(&n_hit, mult(n_hit, -1));
	return (n_hit);
}

t_vec3	compute_nhit_sp(t_sphere *sp, t_vec3 hit_point, t_vec3 cam_pos)
{
	t_vec3	n_hit;

	eq_vector(&n_hit, normalize(minus(hit_point, sp->center)));
	if (norme(minus(cam_pos, sp->center)) < sp->radius)
		eq_vector(&n_hit, mult(n_hit, -1));
	return (n_hit);
}

t_vec3	compute_nhit_pl(t_plane *pl, t_vec3 hit_point, t_vec3 cam_pos)
{
	t_vec3	n_hit;

	eq_vector(&n_hit, normalize(pl->orient));
	if (scalaire_product(normalize(minus(hit_point, cam_pos)), n_hit) > 0)
		eq_vector(&n_hit, mult(n_hit, -1));
	return (n_hit);
}
