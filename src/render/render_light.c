/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:55:16 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/15 12:35:54 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	discriminent_light(t_ray r, t_light s, double *p, t_point sph)
{
	t_vec3	oc;
	double	discr;

	oc = minus(r.orig, sph);
	p[eqa] = length_squared(&r.dir);
	p[eqb] = dot(oc, r.dir);
	p[eqc] = length_squared(&oc) - s.radius * s.radius;
	discr = p[eqb] * p[eqb] - p[eqa] * p[eqc];
	return (discr);
}

void	set_n(t_record *rec, t_ray r, t_point light, t_light l)
{
	rec->hit_point = plus(r.orig, mult((r.dir), rec->t));
	rec->normal = divis(minus(rec->hit_point, light), l.radius);
	rec->light_level = 1;
}

int	hit_light(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	double	root;
	double	discr;
	double	p[3];
	double	sqrt_discr;
	t_light	l;

	(void)light;
	(void)limit;
	l = *((t_light *)rec->closest);
	discr = discriminent_light(r, l, p, light);
	if (discr < 0)
		return (0);
	sqrt_discr = sqrt(discr);
	root = (-p[eqb] - sqrt_discr) / p[eqa];
	if (root < 0)
	{
		root = (-p[eqb] + sqrt_discr) / p[eqa];
		if (root < 0)
			return (0);
	}
	rec->t = root;
	set_n(rec, r, light, l);
	rec->color = l.color;
	rec->type = L;
	return (1);
}
