/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:19:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/24 16:54:09 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	discr_cyl(t_ray r, t_cyl s, double *p)
{
	// t_vec3	oc;
	double	discr;
	(void)s;
	// oc = minus(r.orig, s.center);
	p[_A] = (r.dir.x * r.dir.x) + (r.dir.y * r.dir.y);
	p[_B] = 2 * (r.dir.x * (r.orig.x)) +  2 * (r.dir.y * (r.orig.y));
	// p[_C] = pow((r.orig.x), 2) + pow((r.orig.y), 2) - (pow(s.radius, 2));
	p[_C] = (r.orig.x) * (r.orig.x) + (r.orig.y) * (r.orig.y) - 1;
	discr = p[_B] * p[_B] - 4 * (p[_A] * p[_C]);
	return (discr);
}

int	hit_cylinder(t_record *rec, t_ray r, t_vec2 limit, t_point light)
{

}
