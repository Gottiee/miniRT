/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/24 15:21:58 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	discr_cyl(t_ray r, t_cyl s, double *p)
{
	// t_vec3	oc;
	double	discr;
	(void)s;
	// oc = minus(r.orig, s.center);
	p[_A] = (r.orig.x * r.orig.x) + (r.orig.y * r.orig.y);
	p[_B] = 2 * (r.orig.x * (r.dir.x)) + r.orig.y * (r.dir.y);
	// p[_C] = pow((r.dir.x), 2) + pow((r.dir.y), 2) - (pow(s.radius, 2));
	p[_C] = (r.dir.x) * (r.dir.x) + (r.dir.y) * (r.dir.y) - s.radius * s.radius;
	discr = p[_B] * p[_B] - 4 * (p[_A] * p[_C]);
	return (discr);
}

int	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	double		root1;
	double		root2;
	double		z1;
	double		z2;
	double		discr;
	double		p[3];
	double		sqrt_discr;
	t_cyl		s;
	
	(void) light;
	s = *((t_cyl *)rec->closest);
	discr = discr_cyl(r, s, p);
	rec->discr = discr;
	if (discr < 0)
		return (0);
	sqrt_discr = sqrt(discr);
	rec->light_level = 1;
	rec->color = s.color;
	rec->type = CY;
	return (1);
	root1 = (-p[_B] - sqrt_discr) / 2 * p[_A];
	root2 = (-p[_B] + sqrt_discr) / 2 * p[_A];
	// if (root < limit.x || root > limit.y)
	// {
	// 	root = (-p[_B] + sqrt_discr) / 2 * p[_A];
	// 	if (root < limit.x || root > limit.y)
	// 		return (0);
	// }
	z1 = r.orig.z + root1 * r.dir.z;
	z2 = r.orig.z + root2 * r.dir.z;
	if (!((z1 >= s.center.z && z1 <= s.center.y + s.height)
	 	&& (z2 >= s.center.z && z2 <= s.center.y + s.height))) 
		return (0);
	rec->t = clamp(root1, 0.0, limit.y);
	rec->hit_point = at(r, rec->t);
	rec->normal = new_vec(rec->hit_point.x - s.center.x, 0, rec->hit_point.y - s.center.y);
	set_face(r, rec->normal, rec);
	rec->type = CY;
	return (1);
}
