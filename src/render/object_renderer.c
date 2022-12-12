/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/12/12 23:26:00 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

float	get_intersection(t_hit_lst *temp, t_vec3 raydir, t_vec3 cam_pos, t_vec3 *phit)
{
	if (temp->type == SP)
	{
		return (inter_sphere(raydir, cam_pos, temp->object, phit));
	}
	if (temp->type == PL)
	{

		return (inter_plan(raydir, cam_pos, temp->object, phit));
	}
	if (temp->type == CY)
	{
		return (inter_cylindre(raydir, cam_pos, temp->object, phit));
	}
	if (temp->type == L)
	{
		return (inter_light(raydir, cam_pos, temp->object, phit));
	}
	return (0);
}

t_vec3	hit_global(t_ray r, double *t_min, t_hit_lst **obj, int shad)
{
	t_hit_lst	*tmp;
	t_vec3		p_hit;
	t_vec3		p_hit_temp;
	double		t;

	tmp = *obj;
	*t_min = DBL_MAX;
	while (tmp)
	{
		t = get_intersection(tmp, r.dir, r.orig, &p_hit_temp);
		if (t && t < *t_min)
		{
			eq_vector(&p_hit, p_hit_temp);
			*t_min = t;
			*obj = tmp;
		}
		tmp = tmp->next;
	}
	if (shad && (*obj)->type == L)
		*t_min = DBL_MAX;
	return (p_hit);
}

// int	hit_global(t_ray r, t_record *rec, t_point light)
// {
// 	t_hit_lst	*list;
// 	t_record	rec_tmp;
// 	t_vec2		limit;
// 	int			hit_any;
// 	int 		(*hit[8])(t_record *rec, t_ray r, t_vec2 limit, t_point light);
	
// 	init_pointer(hit);
// 	limit.x = 0;
// 	limit.y = DBL_MAX;
// 	hit_any = 0;
// 	list = get_hit(NULL, 0);
// 	while (list)
// 	{
// 		rec_tmp.closest = list->object;
// 		rec_tmp.type = 0;
// 		if (hit[list->type](&rec_tmp, r, limit, light))
// 		{
// 			hit_any = 1;
// 			limit.y = rec_tmp.t;
// 			*rec = rec_tmp;
// 		}
// 		list = list->next;
// 	}
// 	if (!hit_any)
// 		return (0);
// 	return (1);
// }

