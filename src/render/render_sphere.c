/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/20 17:47:23 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

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

int	hit_sphere(t_record *rec, t_ray r, t_vec2 limit)
{
	double	root;
	double	discr;
	double	p[3];
	double	sqrt_discr;
	
	discr = discriminent(r, rec->closest, p);
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
	return (1);
}