/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/18 15:56:13 by gmansuy          ###   ########.fr       */
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
	double	a;
	double	b;
	double	c;
	double	discr;
	
	oc = minus(r.orig, s.center);
	a = length_squared(&r.dir);
	b = dot(oc, r.dir);
	c = length_squared(&oc) - s.radius * s.radius;
	discr = b * b - a * c;
	p[0] = a;
	p[1] = b;
	p[2] = c;
	return (discr);
}

int	hit_sphere(t_record *rec, t_ray r, t_sphere *s, t_vec2 limit)
{
	double	root;
	double	discr;
	double	p[3];
	double	sqrt_discr;
	
	discr = discriminent(r, *s, p);
	if (discr < 0)
		return (0);
	sqrt_discr = sqrt(discr);
	root = (-p[1] - sqrt_discr) / p[0];
	if (root < limit.x || root > limit.y)
	{
		root = (-p[1] + sqrt_discr) / p[0];
		if (root < limit.x || root > limit.y)
			return (0);
	}
	rec->t = root;
	rec->p = at(r, rec->t);
	rec->normal = divis(minus(rec->p, s->center), s->radius);
	set_face(r, rec->normal, rec);
	rec->sphere_color = plus(mult(rec->normal, 0.5), new_vec(0.5, 0.5, 0.5));
	//sphere color = normal * 0.5 + 0.5 = couleurs de 0 a 1 pour eviter le clamp
	return (1);
}