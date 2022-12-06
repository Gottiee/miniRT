/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/05 10:42:05 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec3	set_cyl_normal(t_cyl c, t_point intersection, t_ray r)
{
	double	t;
	double	res;
	t_point	pt;
	t_point	bottom;
	t_vec3	normal;

	bottom = plus(c.center, mult(c.orient, c.height));
	t = dot(minus(intersection, bottom), c.orient);
	pt = plus(bottom, mult(c.orient, t));
	normal = minus(intersection, pt);
	res = dot(r.dir, normal);
	if (res < 0)
		return (unit_vector(normal));
	return (mult(unit_vector(normal), -1));
}

double	discr_cyl(t_ray r, t_cyl c, double *p, t_vec3 *oc)
{
	(void)oc;
	(void)c;
	p[_A] = (r.dir.x * r.dir.x) + (r.dir.z * r.dir.z);
    p[_B] = 2 * (r.orig.x * r.dir.x) + 2 * (r.orig.z * r.dir.z);
    p[_C] = r.orig.x * r.orig.x + r.orig.z * r.orig.z - 1;
	return (p[_B] * p[_B] - 4 * p[_A] * p[_C]);
}


int	cylinder_info(t_ray r, t_cyl c, double *t)
{
	double 	discr;
	double 	p[4];
	// double	m[2];
	t_vec3	oc;

	discr = discr_cyl(r, c, p, &oc);
	if (discr < 0)
		return (0);
	t[0] = -p[_B] - sqrt(discr) / (2 * p[_A]);
	t[1] = -p[_B] + sqrt(discr) / (2 * p[_A]);
	// if (t[0] < t[1])
	// 	t[2] = t[0];
	// else
	// 	t[2] = t[1];	
	return (1);
}

int	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	t_cyl 	c;
	t_point point1;
	double	t[5];
	double	y[2];

	(void)light;
	(void)limit;
	c = *((t_cyl *)rec->closest);
	c.orient = unit_vector(c.orient);
	if (!cylinder_info(r, c, t))
		return (0);
	//  z1 = zE + t1zD and z2 = zE + t2zD
//	
	y[0] = r.orig.y + t[0] * r.dir.y;
	y[1] = r.orig.y + t[1] * r.dir.y;
	//
	rec->t = ft_min(y[0], y[1]);
	if (rec->t < 0)
		rec->t = ft_max(y[0], y[1]);
	if (rec->t < 0)
		return (0);
	if (rec->t == y[0])
		rec->t = t[0];
	else
		rec->t = t[1];
	if (rec->t < limit.x || rec->t >= limit.y)
		return (0);
	rec->hit_point = at(r, rec->t);
	rec->normal = unit_vector(new_vec(rec->hit_point.x, 0.0, -rec->hit_point.z));
	//
	if (rec->hit_point.y < 0 || rec->hit_point.y > 5) //5 = c.height
		return (0);	
	if (r.dir.y != 0.0)		
	{
		t[3] = 0 - r.orig.y / r.dir.y;
		t[4] = 5 - r.orig.y / r.dir.y; //5 = c.height
	}
	t[2] = ft_min(t[3], t[4]);
	if (t[2] < 0)
		t[2] = ft_max(t[3], t[4]);
	if (t[2] >= 0)
	{
		point1 = at(r, t[2]);
		if (point1.x * point1.x + point1.z * point1.z <= 1 * 1 + 0.9) //1 = cradius
		{
			rec->t = ft_min(rec->t, t[2]);
			if (rec->t == t[3])
			{
				rec->normal = new_vec(0.0, -1.0, 0.0);
				rec->hit_point = point1;
			}
			if (rec->t == t[4])
			{
				rec->normal = new_vec(0.0, 1.0, 0.0);
				rec->hit_point = point1;
			}
		}
	}
//	
	rec->light_level = 1;
	rec->color = c.color;
	return (1);
}
