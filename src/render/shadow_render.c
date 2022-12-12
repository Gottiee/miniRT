/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:02 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/12 23:19:19 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	get_luminosity(t_vec3 hit_point, t_vec3 n_hit, double transmission, t_light light)
{
	t_ambiant	*a;
	double		lum;
	// t_vec3	luminosity;
	// t_vec3	lum_dir;
	t_vec3		p_lum;
	double		ratio;
	// double		ld;
	// double		la;
	eq_vector(&p_lum, minus(*light.center, hit_point));
	// eq_vector(&lum_dir, normalize(p_lum));
	// if (transmission == FLT_MAX || transmission > norme(p_lum))
	// 	transmission = 1;
	// else
	// 	transmission = 0.8;
	// ld = transmission * (light.ratio * (1000000.0 / scalaire_product(p_lum, p_lum))) * max(0, scalaire_product(n_hit, lum_dir));
	// la = (a->ratio);
	// luminosity.x = 255 - (light.color.x * (ld / 255)) - (a->color.x * (la / 255));
	// luminosity.y = 255 - (light.color.y * (ld / 255)) - (a->color.y * (la / 255));
	// luminosity.z = 255 - (light.color.z * (ld / 255)) - (a->color.z * (la / 255));
	// return (luminosity);
	
	(void)a;
	(void)hit_point;
	(void)light;
	(void)n_hit;
	lum = light.ratio * 0.5;
	a = get_amb();
	ratio = a->ratio * 0.5;
	if (transmission != DBL_MAX)
		return (ratio);
	lum = max(dot(unit_vector(p_lum), unit_vector(n_hit)), ratio);
	lum = max(lum / (length(&p_lum) / 5), ratio);
	return (lum);
}

t_color	check_obstruction(t_vec3 hit_point, t_vec3 n_hit, t_hit_lst *objects, t_light light)
{
	t_vec3		lum_dir;
	double		transmission;
	t_hit_lst	*current;
	t_ray		r;
	current = objects;
	eq_vector(&lum_dir, normalize(minus(*light.center, hit_point)));
	r.orig = plus(hit_point, mult(n_hit, 0.01));
	r.dir = lum_dir;
	objects = get_hit(NULL, 0);
	hit_global(r, &transmission, &objects, 1);
	if (current->type == SP)
		return (mult(((t_sphere *)current->object)->color, \
		get_luminosity(hit_point, n_hit, transmission, light)));
	else if (current->type == PL)
		return (mult(((t_plane *)current->object)->color, \
		get_luminosity(hit_point, n_hit, transmission, light)));
	else if (current->type == CY)
		return (mult(((t_cyl *)current->object)->color, \
		get_luminosity(hit_point, n_hit, transmission, light)));
	else
		return (mult((((t_sphere *)current->object)->color), 0));
	
	// if (current->type == SP)
	// 	return (minus(((t_sphere *)current->object)->color, get_luminosity(hit_point, n_hit, transmission, light)));
	// else if (current->type == PL)
	// 	return (minus(((t_plane *)current->object)->color, get_luminosity(hit_point, n_hit, transmission, light)));
	// else if (current->type == CY)
	// 	return (minus(((t_cyl *)current->object)->color, get_luminosity(hit_point, n_hit, transmission, light)));
	// else
	// 	return (((t_sphere *)current->object)->color);
}

t_color	shadow_render(t_vec3 hit_point, t_light light, t_hit_lst *obj, t_ray r)
{
	t_vec3	n_hit;

	if (obj->type == SP)
		eq_vector(&n_hit, compute_nhit_sp(((t_sphere *)obj->object), hit_point, r.orig));
	else if (obj->type == PL)
		eq_vector(&n_hit, compute_nhit_pl(((t_plane *)obj->object), hit_point, r.orig));
	else if (obj->type == CY)
		eq_vector(&n_hit, compute_nhit_cy((t_cyl *)obj->object, hit_point, r.orig));
	else if (obj->type == L)
		return (new_vec(1, 1, 1));
	return (check_obstruction(hit_point, n_hit, obj, light));
}
