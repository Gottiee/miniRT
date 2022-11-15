/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:39:40 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/15 19:06:40 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int	hit_sphere(t_point *center, double radius, t_ray r)
{
	double		a;
	double		b;
	double		c;
	double		discr;

	min_equal(&r.orig, center);
	a = dot(&r.dir, &r.dir);
	b = 2.0 * dot(&r.orig, &r.dir);
	c = dot(&r.orig, &r.orig) - radius * radius;
	discr = b * b - 4 * a * c;
	return (discr > 0);
}