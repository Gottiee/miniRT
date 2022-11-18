/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/18 17:43:18 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	set_face(t_ray r, t_vec3 outward, t_record *rec)
{
		rec->front_face = dot(r.dir, outward) < 0;
		rec->normal = outward;
		if (!rec->front_face)
				mult_equal(&rec->normal, -1);
}

double	discriminent(t_ray r, t_sphere s, double *p)
{
	t_vec3	oc;
	double	discr;
	
	oc = minus(r.orig, s.center);
	p[A] = length_squared(&r.dir);
	p[B] = dot(oc, r.dir);
	p[C] = length_squared(&oc) - s.radius * s.radius;
	discr = p[B] * p[B] - p[A] * p[C];
	return (discr);
}

int	hit_sphere(t_record *rec, t_ray r, t_sphere *s, t_vec2 limit, t_point light)
{
	double	root;
	double	discr;
	double	p[3];
	double	sqrt_discr;
	
	discr = discriminent(r, *s, p);
	if (discr < 0)
		return (0);
	sqrt_discr = sqrt(discr);
	root = (-p[B] - sqrt_discr) / p[A];
	if (root < limit.x || root > limit.y)
	{
		root = (-p[B] + sqrt_discr) / p[A];
		if (root < limit.x || root > limit.y)
			return (0);
	}
	rec->t = root;
	rec->p = at(r, rec->t);
	rec->normal = divis(minus(rec->p, s->center), s->radius);
	set_face(r, rec->normal, rec);
	rec->sphere_color = plus(mult(rec->normal, 0.5), new_vec(0.5, 0.5, 0.5));
	rec->light_level = dot(rec->normal, mult(light, -1));
	//Peut etre un debut d'antialiasing, a tester
	// if (discr < 0.001)
	// 	rec->light_level *= 0.5;
	return (1);
}