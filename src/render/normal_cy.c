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

t_vec3	get_normal_cy(t_cyl *cl, t_vec3 hit_point)
{
	t_vec3		b_phit;
	t_vec3		normal;
	double		hyp;
	double		h;

	eq_vector(&b_phit, minus(hit_point, cl->center));
	eq_vector(&cl->orient, normalize(cl->orient));
	hyp = norme(b_phit);
	h = sqrtf((hyp * hyp) - (cl->radius * cl->radius));
	if (cl->inter_code == 1)
		eq_vector(&normal, normalize(minus(hit_point, \
		plus(cl->center, mult(cl->orient, h)))));
	else if (cl->inter_code == 2)
		eq_vector(&normal, mult(cl->orient, -1));
	else
		eq_vector(&normal, cl->orient);
	return (normal);
}

t_vec3	normal_cy(t_cyl *cy, t_vec3 hit_point, t_vec3 cam_pos)
{
	t_vec3	normal;

	eq_vector(&normal, get_normal_cy(cy, hit_point));
	if (dot(normalize(minus(hit_point, cam_pos)), normal) > 0)
		eq_vector(&normal, mult(normal, -1));
	return (normal);
}