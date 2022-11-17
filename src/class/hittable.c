/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/11/17 22:58:09 by marvin           ###   ########.fr       */
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
		double	a;
		double	b;
		double	c;
		double	discr;
		double	root;   

		min_equal(&r.orig, &s->center);
		a = length_squared(&r.dir);
		b = dot(&r.orig, &r.dir);
		c = length_squared(&r.dir) - s->radius * s->radius;
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
		//changer at
		at(&r, rec->t);
		rec->p = r.dir;	
		min_equal(&r.dir, &s->center);
		div_equal(&r.dir, s->radius);
		set_face(r, &r.dir, rec);
		//sphere color = normal * 0.5 + 0.5 = couleurs de 0 a 1 pour eviter le clamp
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
		//poiteur sur fonction pour modifier et ne pas aller hit sphere tout le tempps?
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
