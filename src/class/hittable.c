/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/11/16 13:25:17 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	hit(t_ray r, t_record *rec, t_sphere s)
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	root;
	
	min_equal(&r.orig, &s.center);
	a = length_squared(&r.dir);
	b = dot(&r.orig, &r.dir);
	c = length_squared(&r.dir) - s.radius * s.radius;
	discr = b * b - a * c;
	if (discr < 0)
		return (0);
	discr = sqrt(discr);
	root = (-b - discr) / a;
	if (root < rec->t_min || root > rec->t_max)
	{
		root = (-b + discr) / a;
		if (root < rec->t_min || root > rec->t_max)
			return (0);
	}
	rec->t = root;
	at(&r, rec->t);
	rec->p = r.dir;	
	min_equal(&r.dir, &s.center);
	div_equal(&r.dir, s.radius);
	rec->normal = r.dir;
	return (1);
}
