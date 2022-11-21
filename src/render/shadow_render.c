/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/21 20:11:24 by gmansuy          ###   ########.fr       */
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

void	shadow_render(t_record *rec, t_point light)
{
	t_ray		path;
	t_hit_lst	*list;
	int			curr_obj;
	t_record	shadow;
	t_vec2		limit;
	t_sphere	s;

	s = *((t_sphere *)rec->closest);
	list = get_hit(NULL, 0);
	// retirer le plus et le minus ?
	path.orig = plus(rec->hit_point, s.center);
	path.dir = minus(light, s.center);
	curr_obj = 0;
	limit.x = 0;
	limit.y = DBL_MAX;
	while (list)
	{
		if (list->type == L)
		{
			list = list->next;
			curr_obj ++;
			continue;	
		}
		shadow.closest = list->object;
		if (list->id != rec->obj_id && hit_sphere(&shadow, path, limit, light) /*hit_obstacle(path, list->object)*/)
		{
			//LIGHT LEVEL = lumiere amibiante
			rec->light_level *= 0.2;
			break ;
			// shadow.hit_point = at(path, shadow.t);
			// shadow.normal = divis(minus(shadow.hit_point, ((t_sphere *)shadow.closest)->center),
			// 		((t_sphere *)shadow.closest)->radius);
			// shadow.light_level = dot(path.dir, mult(shadow.normal, -1)	);
			// rec->light_level *= 1 - shadow.light_level;
			// break ;
		}
		list = list->next;
		curr_obj ++;
	}
}

// void	shadow_render(t_record *rec, t_point light)
// {
	
// }