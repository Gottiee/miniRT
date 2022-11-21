/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/21 19:03:21 by gmansuy          ###   ########.fr       */
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

void	set_normal(t_record *rec, t_ray r, t_point light, t_sphere s)
{
	rec->hit_point = at(r, rec->t);
	rec->normal = divis(minus(rec->hit_point, s.center), s.radius);
	set_face(r, rec->normal, rec);
	rec->light_level = clamp(dot(rec->normal, minus(light, s.center)), 0, 1)/* * 1 - rec->t / 2*/;
}

double	discriminent(t_ray r, t_sphere s, double *p)
{
	t_vec3	oc;
	double	discr;
	
	oc = minus(r.orig, s.center);
	p[_A] = length_squared(&r.dir);
	p[_B] = dot(oc, r.dir);
	p[_C] = length_squared(&oc) - s.radius * s.radius;
	discr = p[_B] * p[_B] - p[_A] * p[_C];
	return (discr);
}

int	hit_sphere(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	double		root;
	double		discr;
	double		p[3];
	double		sqrt_discr;
	t_sphere	s;
	
	s = *((t_sphere *)rec->closest);
	discr = discriminent(r, s, p);
	if (discr < 0)
		return (0);
	sqrt_discr = sqrt(discr);
	root = (-p[_B] - sqrt_discr) / p[_A];
	if (root < limit.x || root > limit.y)
	{
		root = (-p[_B] + sqrt_discr) / p[_A];
		if (root < limit.x || root > limit.y)
			return (0);
	}
	rec->t = clamp(root, 0.0, limit.y);
	set_normal(rec, r, light, s);
	rec->color = s.color;
	rec->type = SP;
	return (1);
}