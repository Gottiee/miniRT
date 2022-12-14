/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/12/13 11:45:49 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	intersect(t_hit_lst *lst, t_ray r, t_vec3 *hit)
{
	if (lst->type == L)
		return (inter_light(r.dir, r.orig, lst->object, hit));
	if (lst->type == PL)
		return (inter_plan(r.dir, r.orig, lst->object, hit));
	if (lst->type == SP)
		return (inter_sphere(r.dir, r.orig, lst->object, hit));
	if (lst->type == CY)
		return (inter_cylindre(r.dir, r.orig, lst->object, hit));
	return (0);
}

t_vec3	hit_global(t_ray r, double *t_max, t_hit_lst **obj, int shad)
{
	t_hit_lst	*tmp;
	t_vec3		p_hit;
	t_vec3		p_hit_temp;
	double		t;

	tmp = *obj;
	*t_max = DBL_MAX;
	while (tmp)
	{
		t = intersect(tmp, r, &p_hit_temp);
		if (t && t < *t_max)
		{
			eq_vector(&p_hit, p_hit_temp);
			*t_max = t;
			*obj = tmp;
		}
		tmp = tmp->next;
	}
	if (shad && (*obj)->type == L)
		*t_max = DBL_MAX;
	return (p_hit);
}
