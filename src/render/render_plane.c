/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:00:38 by eedy              #+#    #+#             */
/*   Updated: 2022/12/14 18:09:54 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	hit_plane(t_record *rec, t_ray r, t_vec2 limit, t_vec3 light)
{
	t_plane	p;
	double	t;
	double	d;
	t_vec3	polo;

	(void)light;
	(void)limit;
	p = *((t_plane *)rec->closest);
	t = dot(p.orient, minus(p.center, r.orig)) / dot(p.orient, r.dir);
	d = dot(p.orient, r.dir);
	if (d < 1e-6)
		return (0);
	polo = minus(p.center, r.orig);
	t = dot(polo, p.orient) / d;
	if (t < 0)
		return (0);
	rec->t = t;
	rec->light_level = 1;
	rec->color = p.color;
	rec->type = PL;
	rec->hit_point = at(r, rec->t);
	rec->normal = p.orient;
	set_face(r, rec->normal, rec);
	return (1);
}
