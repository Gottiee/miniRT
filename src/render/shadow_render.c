/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/21 13:47:04 by gmansuy          ###   ########.fr       */
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

// void	shadow_render(t_record *rec, t_point light)
// {
// 	t_ray		path;
// 	t_hit_lst	*list;
// 	int			curr_obj;
// 	t_record	shadow;
// 	t_vec2		limit;

// 	list = get_hit(NULL, 0);
// 	path.orig = plus(rec->hit_point, rec->closest.center);
// 	path.dir = unit_vector(minus(mult(light, -1), rec->closest.center));
// 	curr_obj = 0;
// 	limit.x = 0;
// 	limit.y = DBL_MAX;
// 	while (list)
// 	{
// 		shadow.closest = *((t_sphere *)list->object);
// 		if (list->id != rec->obj_id && hit_sphere(&shadow, path, limit) /*hit_obstacle(path, list->object)*/)
// 		{
// 			shadow.hit_point = at(path, shadow.t);
// 			shadow.normal = divis(minus(shadow.hit_point, shadow.closest.center),
// 					shadow.closest.radius);
// 			shadow.light_level = dot(mult(path.dir, -1), shadow.normal);
// 			// printf("%f\n", shadow.light_level);
// 			rec->light_level *= 1 - pow(shadow.light_level, 2);
// 			break ;
// 		}
// 		list = list->next;
// 		curr_obj ++;
// 	}
// }