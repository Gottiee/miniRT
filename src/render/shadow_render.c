/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/15 13:59:48 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	setl(t_vec2 *limit)
{
	limit->x = 0;
	limit->y = DBL_MAX;
}

int	hit_shadow(t_ray r, t_record *rec, t_point light)
{
	t_hit_lst	*list;
	t_record	rec_tmp;
	t_vec2		limit;
	int			(*hit[8])(t_record *rec, t_ray r, t_vec2 limit, t_point light);

	init_pointer(hit);
	setl(&limit);
	list = get_hit(NULL, 0);
	while (list)
	{
		rec_tmp.closest = list->object;
		rec_tmp.type = 0;
		if (hit[list->type](&rec_tmp, r, limit, light))
		{
			if (rec_tmp.t < limit.y)
			{
				limit.y = rec_tmp.t;
				*rec = rec_tmp;
				rec->obj_id = list->id;
			}
		}
		list = list->next;
	}
	return (rec->type != L);
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
	t_vec3		p;

	l = get_light();
	a = get_amb();
	rec->light_level = l->ratio * 2;
	path.orig = plus(rec->hit_point, mult(rec->normal, 0.01));
	path.dir = normalize(minus(light, rec->hit_point));
	p = minus(light, path.orig);
	if (hit_shadow(path, &shadow, light))
		rec->light_level = a->ratio * 0.5;
	else
	{
		rec->light_level *= greatest(dot(unit_vector(p), \
		unit_vector(rec->normal)), a->ratio * 0.5);
		rec->light_level = greatest(rec->light_level / (length(&p) / 5), \
		a->ratio * 0.5);
	}
	rec->light_level = greatest(rec->light_level, a->ratio * 0.5);
	rec->color = unit_vector(plus(rec->color, \
	mult(divis(a->color, rec->light_level), a->ratio * 0.5)));
}
