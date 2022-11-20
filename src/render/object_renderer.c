/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/11/20 18:05:25 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	set_face(t_ray r, t_vec3 outward, t_record *rec)
{
	int	front_face;
	
	front_face = dot(r.dir, outward) < 0;
	rec->normal = outward;
	if (!front_face)
		mult_equal(&rec->normal, -1);
}

void	set_normal(t_record *rec, t_ray r, t_point light)
{
	rec->closest.color = plus(mult(rec->normal, 0.5), new_vec(0.5, 0.5, 0.5));
	rec->hit_point = at(r, rec->t);
	rec->normal = divis(minus(rec->hit_point, rec->closest.center), rec->closest.radius);
	set_face(r, rec->normal, rec);
			// printv(light);
	rec->light_level = dot(rec->normal, mult(light, -1));
}

int	hit_global(t_ray r, t_record *rec, t_point light)
{
	t_hit_lst	*list;
	t_record	rec_tmp;
	t_vec2		limit;
	int			hit_any;	

	limit.x = 0;
	limit.y = DBL_MAX;
	hit_any = 0;
	list = get_hit(NULL);
	while (list)
	{
		rec_tmp.closest = *((t_sphere *)list->object);
		//poiteur sur fonction pour modifier et ne pas aller hit sphere tout le tempps?
		if (hit_sphere(&rec_tmp, r, limit))
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
	set_normal(rec, r, light);
	shadow_render(rec, light);
	return (1);
}

//Peut etre un debut d'antialiasing, a tester
// if (discr < 0.001)
// 	rec->light_level *= 0.5;
