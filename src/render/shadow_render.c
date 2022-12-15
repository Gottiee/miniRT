/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/13 18:16:39 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	light_level(t_vec3 hit_point, t_vec3 normal, double shadow_t, t_light light)
{
	t_ambiant	*a;
	t_vec3		l_point;
	double		lum;
	double		ratio;

	l_point = minus(*light.center, hit_point);
	lum = light.ratio * 0.5;
	a = get_amb();
	ratio = a->ratio * 0.3;
	if (shadow_t != DBL_MAX)
		return (ratio);
	lum = max(dot(unit_vector(l_point), unit_vector(normal)), ratio);
	lum = max(lum / (length(&l_point) / 5), ratio);
	return (lum);
}

t_color	get_color(t_color obj_color, double lum)
{
	t_color	color;
	t_ambiant	*a;

	a = get_amb();
	color = unit_vector(plus(obj_color, mult(divis(a->color, lum), a->ratio * 0.3)));
	return (mult(color, lum));
}

t_color	hit_shadow(t_vec3 hit_point, t_vec3 normal, t_hit_lst *objects, t_light light)
{
	t_ray		r;
	t_hit_lst	*current;
	double		shadow_t;

	current = objects;
	r.orig = plus(hit_point, mult(normal, 0.0001));
	r.dir = *light.center;
	objects = get_hit(NULL, 0);
	hit_global(r, &shadow_t, &objects, 1);
	if (current->type == SP)
		return (get_color(((t_sphere *)current->object)->color, \
		light_level(hit_point, normal, shadow_t, light)));
	else if (current->type == PL)
		return (get_color(((t_plane *)current->object)->color, \
		light_level(hit_point, normal, shadow_t, light)));
	else if (current->type == CY)
		return (get_color(((t_cyl *)current->object)->color, \
		light_level(hit_point, normal, shadow_t, light)));
	else
		return (new_vec(1, 1, 1));
}

t_color	shadow_render(t_vec3 hit_point, t_light light, t_hit_lst *obj, t_ray r, int n)
{
	t_vec3	normal;

	if (obj->type == SP)
		normal = normal_sp(((t_sphere *)obj->object), hit_point, r.orig);
	else if (obj->type == PL)
		normal = normal_pl(((t_plane *)obj->object), hit_point, r.orig);
	else if (obj->type == CY)
		normal = normal_cy((t_cyl *)obj->object, hit_point, r.orig);
	else if (obj->type == L)
		return (new_vec(1, 1, 1));
	if (n)
		return (mult(plus(normal, new_vec(1, 1, 1)), 0.5));
	return (hit_shadow(hit_point, normal, obj, light));
	//ambiance couleur pas encore prise en compte
}
