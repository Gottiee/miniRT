/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/29 17:57:52 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

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
	if (!hit_any || rec->type == L)
		return (0);
	return (1);
}

double	greatest(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	shadow_render(t_record *rec, t_point light)
{
	t_ray		path;
	t_record	shadow;
	t_light		*l;
	t_ambiant	*a;

	l = get_light();
	a = get_amb(); //si pas de amb ?
	(void)a;
	rec->light_level = l->ratio;
	path.orig = plus(rec->hit_point, mult(rec->normal, 0.000001));
	path.dir = minus(light, path.orig);
	if (hit_shadow(path, &shadow, light))
		rec->light_level = a->ratio;
	else
	{
		rec->light_level *= dot(unit_vector(path.dir), unit_vector(rec->normal));
		rec->light_level = greatest(rec->light_level / (length(&path.dir) / 2), a->ratio);
	}
}
