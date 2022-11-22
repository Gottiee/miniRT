/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/22 17:35:15 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

// int	hit_obstacle(t_ray r, t_sphere *s)
// {
// 	t_vec3	oc;
// 	double 	a;	
// 	double 	b;	
// 	double 	c;	
// 	double 	discr;	

// 	oc = minus(r.orig, s->center);
// 	a = length_squared(&r.dir);
// 	b = dot(oc, r.dir);
// 	c = length_squared(&oc) - s->radius * s->radius;
// 	discr = b * b - a * c;
// 	return (discr >= 0);
// }

int	hit_shadow(t_ray r, t_record *rec, t_point light)
{
	t_hit_lst	*list;
	t_record	rec_tmp;
	t_vec2		limit;
	int			hit_any;
	int 		(*hit[8])(t_record *rec, t_ray r, t_vec2 limit, t_point light);
	
	init_pointer(hit);
	limit.x = 0;
	limit.y = DBL_MAX;
	hit_any = 0;
	list = get_hit(NULL, 0);
	while (list)
	{
		if (list->type == L)
		{
			list = list->next;
			continue ;
		}
		rec_tmp.closest = list->object;
		rec_tmp.type = 0;
		if (hit[list->type](&rec_tmp, r, limit, light))
		{
			hit_any = 1;
			limit.y = rec_tmp.t;
			*rec = rec_tmp;
			rec->obj_id = list->id;
		}
		list = list->next;
	}
	if (!hit_any)
		return (0);
	return (1);
}

void	shadow_render(t_record *rec, t_point light)
{
	t_ray		path;
	t_record	shadow;

	shadow.light = 1;
	rec->light_level = 1;
	path.orig = plus(rec->hit_point, mult(rec->normal, 0.000001));
	path.dir = light;
	hit_shadow(path, &shadow, light);
	if (shadow.discr > 0)
	{
		rec->light_level = 0.1;
	}
}
