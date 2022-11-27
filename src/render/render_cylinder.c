/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/27 18:00:30 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	discr_cyl(t_ray r, t_cyl c, double *p, t_vec3 *oc)
{
	*oc = minus(r.orig, c.center);
	p[_A] = dot(r.dir, r.dir) - pow(dot(r.dir, c.orient), 2);
	p[_B] = 2 * (dot(r.dir, *oc) - dot(r.dir, c.orient) * dot(*oc, c.orient));
	p[_C] = dot(*oc, *oc) - pow(dot(*oc, c.orient), 2) - pow(c.radius, 2);
	return (p[_B] * p[_B] - 4 * p[_A] * p[_C]);
}


double	cylinder_info(t_ray r, t_cyl c)
{
	double 	discr;
	double 	p[4];
	double	t1;
	double	t2;
	double	m1;
	double	m2;
	t_vec3	oc;

	discr = discr_cyl(r, c, p, &oc);
		// printf("%f\n", discr);
	if (discr < 0)
		return (0);
	t1 = -p[_B] + sqrt(discr) / (2 * p[_A]);
	t2 = -p[_B] - sqrt(discr) / (2 * p[_A]);
    if (t1 < 0)
		return (0);
	m1 = dot(r.dir, c.orient) * t2 + dot(oc, c.orient);
	m2 = dot(r.dir, c.orient) * t1 + dot(oc, c.orient);
	if (m1 >= 0 && m1 <= c.height)
        return (t2);
    else if (m2 >= 0 && m2 <= c.height)
        return (t1);
    return (0);
}

t_vec3	set_cyl_normal(t_cyl c, t_point intersection, t_ray r)
{
	double	t;
	double	res;
	t_point	pt;
	t_point	bottom;
	t_vec3	normal;

	bottom = plus(c.center, mult(c.orient, c.height));
	// ft_vec_add(cyl->p, ft_vec_mul(cyl->height, cyl->orient));
	t = dot(minus(intersection, bottom), c.orient);
	pt = plus(bottom, mult(c.orient, t));
	normal = minus(intersection, pt);
	res = dot(r.dir, normal);	
	if (res < 0)
		return (normal);
	return (mult(normal, -1));
}

int	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	t_cyl 	c;

	(void)light;
	(void)limit;
	c = *((t_cyl *)rec->closest);
	rec->t = cylinder_info(r, c);
	if (!rec->t)
		return (0);
	if (rec->t < limit.x || rec->t > limit.y)
		return (0);
	rec->hit_point = at(r, rec->t);
	rec->normal = set_cyl_normal(c, rec->hit_point, r);
	rec->light_level = 1;
	rec->color = c.color;
	return (1);
}

// double	discr_cyl(t_ray r, t_cyl c, double *p)
// {
// 	double	discr;
// 	//a = vx * vx + vy * vy
// 	//b = 2 * (px * vx + py * vy)
// 	//c = px * px + py * py - radius * radius
// 	// v -> r.dir
// 	// p -> r.orig
// 	// radius -> c.radius
// 	p[_A] = r.dir.x * r.dir.x + r.dir.y * r.dir.y;
// 	p[_B] = 2 * (r.orig.x * r.dir.x + r.orig.y * r.dir.y);
// 	p[_C] = r.orig.x * r.orig.x + r.orig.y * r.orig.y - c.radius * c.radius;
// 	discr = p[_B] * p[_B] - 4 * p[_A] * p[_C];
// 	return (discr);
// }

// int	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
// {
// 	double 	discr;
// 	double 	p[3];
// 	t_cyl 	c;
	
// 	(void)light;
// 	(void)limit;
// 	c = *((t_cyl *)rec->closest);
// 	discr = discr_cyl(r, c, p);
// 	if (discr < 0)
// 		return (0);
// 	// if ((t1 < limit.x || t1 > limit.y) && (t2 < limit.x || t2 > limit.y))
// 	// 		return (0);
// 	rec->t = -p[_B] - sqrt(discr) / 2 * p[_A];
// 	rec->hit_point = at(r, rec->t);
// 	if (rec->hit_point.z < c.center.z || rec->hit_point.z > c.center.z + c.height)
// 	{
// 		rec->t = -p[_B] + sqrt(discr) / 2 * p[_A];
// 		rec->hit_point = at(r, rec->t);				
// 		if (rec->hit_point.z < c.center.z || rec->hit_point.z > c.center.z + c.height)
// 			return (0);
// 	}
// 	rec->color = c.color;
// 	rec->type = CY;
// 	rec->normal = divis(minus(rec->hit_point, c.center), c.radius);
// 	rec->light_level = 1;
// 	return (1);
// }
