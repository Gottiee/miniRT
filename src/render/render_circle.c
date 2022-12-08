/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:36:18 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/08 17:59:52 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	plane(t_record *rec, t_ray r, t_vec2 limit, t_vec3 light)
{
	t_circle	p;
	double		t;
	double		d;
	t_vec3		polo;

	(void)light;
	p = *((t_circle *)rec->closest);
	t = dot(p.orient, minus(p.center, r.orig)) / dot(p.orient, r.dir);
	d = dot(p.orient, r.dir);
	if (d < 1e-6)
		return (0);
	polo = minus(p.center, r.orig);
	t = dot(polo, p.orient) / d;
	if (t < 0)
		return (0);
	if (t < limit.x || t > limit.y)
		return (0);
	rec->t = t;
	rec->light_level = 1;
	rec->color = p.color;
	rec->hit_point = at(r, rec->t);
	rec->normal = p.orient;
	set_face(r, rec->normal, rec);
	// printv(rec->normal);
	// printv(p.orient);
	return (1);
}

int	hit_circle(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	t_vec3		v;
	// t_vec3		p;
	double		d;
	t_circle	c;

	c = *((t_circle *)rec->closest);
	if (plane(rec, r, limit, light))
	{
		// p = plus(r.orig, mult(r.dir, rec->t));
		v = minus(rec->hit_point, c.center);
		d = dot(v, v);
		rec->type = CE;
		set_face(r, rec->normal, rec);
		return (sqrtf(d) <= c.radius);
	}
	return (0);
}