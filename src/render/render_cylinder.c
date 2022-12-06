/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/06 18:09:42 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	discr_cyl(t_ray r, t_cyl c, double *p)
{
	t_point	r0; //origne du rayon
	t_vec3	v;	//orientation du rayon (vecteur unitaire)
	t_point	rt;	//position ou passe le tube
	t_vec3	s;	//axe du tube
	double	R;	//rayon du tube
	
	r0 = r.orig;
	v = r.dir;
	rt = c.center;
	s = c.orient;
	R = c.radius;

	t_vec3	ra0;
	t_vec3	va;

	ra0 = mult_vec(mult_vec(s, minus(r0, rt)), s);
	va = mult_vec(mult_vec(s, v), s);

	
	p[_A] = dot(va, va);
    p[_B] = dot(mult(ra0, 2), va);
    p[_C] = dot(ra0,  ra0) - R * R;
	return (p[_B] * p[_B] - 4 * p[_A] * p[_C]);
}


int	cylinder_info(t_ray r, t_cyl c, double *t)
{
	double 	discr;
	double 	p[4];

	discr = discr_cyl(r, c, p);
	if (discr < 0)
		return (0);
	// printf("%f\n", discr);
	t[0] = -p[_B] - sqrt(discr) / (2 * p[_A]);
	t[1] = -p[_B] + sqrt(discr) / (2 * p[_A]);
	// printf("%f\n", t[1]);
	if (t[1] < 0)
		return (0);
	t[2] = (t[0] > 0) * t[0] + (t[1] > 0 && t[0] <= 0) * t[1];
	if (t[2])
		return (1);
	return (0);
}

int	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{
	t_cyl 	c;
	double	t[3];

	(void)light;
	(void)limit;
	c = *((t_cyl *)rec->closest);
	if (!cylinder_info(r, c, t))
		return (0);
	// if (t[1] < limit.x || t[1] > limit.y)
	// 	return (0);
	rec->t = t[0];
	// printf("%f\n", rec->t);
	rec->hit_point = at(r, rec->t);
	rec->normal = minus(rec->hit_point, c.center);
	rec->light_level = 1;
	rec->color = c.color;
	return (1);
}
