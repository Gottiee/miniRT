/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/22 14:23:07 by eedy             ###   ########.fr       */
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
	t_record	shadow;

	shadow.light = 1;
	path.dir = rec->hit_point;
	//path.dir = plus(path.dir, mult(rec->normal, 0.1));
	path.orig = light;
	if (hit_global(path, &shadow, light))
		if (rec->obj_id != shadow.obj_id)
			rec->light_level = 0.2;
}
