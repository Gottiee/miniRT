/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/12/14 13:57:13 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	set_face(t_ray r, t_vec *outward, t_record *rec)
{
	rec->front_face = dot(&r.dir, outward) < 0;
	rec->normal = *outward;
	if (!rec->front_face)
		mult_equal(&rec->normal, -1);
}

int	hit_sphere(t_ray r, t_record *rec, t_sphere *s)
{
	t_spe	s;

	s.tmp = r;
	min_equal(&r.orig, &s->center);
	s.a = length_squared(&r.dir);
	s.b = dot(&r.orig, &r.dir);
	s.c = length_squared(&r.orig) - s->radius * s->radius;
	s.discr = s.b * s.b - s.a * s.c;
	if (s.discr < 0)
		return (0);
	s.discr = sqrt(s.discr);
	s.root = (-s.b - s.discr) / s.a;
	if (s.root < rec->t_min || s.root > rec->t_max)
	{
		s.root = (-s.b + s.discr) / s.a;
		if (s.root < rec->t_min || s.root > rec->t_max)
			return (0);
	}
	rec->t = s.root;
	at(&r, rec->t);
	rec->p = r.dir;
	min_equal(&r.dir, &s->center);
	div_equal(&r.dir, s->radius);
	set_face(s.tmp, &r.dir, rec);
	return (1);
}

int	hit_global(t_ray r, t_record *rec, double t_min, double t_max)
{
	t_record	tmp;	
	int			hit_any;	
	t_hit_lst	*list;

	tmp.t_min = t_min;
	tmp.t_max = t_max;
	hit_any = 0;
	list = get_hit(NULL);
	while (list)
	{
		if (hit_sphere(r, &tmp, list->object))
		{
			hit_any = 1;
			tmp.t_max = tmp.t;
			*rec = tmp;
		}
		list = list->next;
	}
	return (hit_any);
}
