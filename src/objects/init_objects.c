/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:06:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/24 14:51:33 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_cylinder(t_vec3 vec, double ray, t_vec3 orient, t_color color)
{
	t_cyl	*s;
	void		*ptr;

	s = magic_malloc(sizeof(t_cyl));
	s->center = vec;
	s->radius = ray;
	s->color = color;
	s->orient = orient;
	s->height = vec.height;
	ptr = s;
	get_hit(ptr, CY);
}

void	init_sphere(t_vec3 vec, double ray, t_color color)
{
	t_sphere	*s;
	void		*ptr;

	s = magic_malloc(sizeof(t_sphere));
	s->center = vec;
	s->radius = ray;
	s->color = color;
	ptr = s;
	get_hit(ptr, SP);
}

void	init_plane(t_vec3 center, t_color color, t_vec3 orient)
{
	t_plane	*p;
	void	*ptr;
	p = magic_malloc(sizeof(t_plane));
	p->center = center;
	p->orient = orient;
	p->color = color;
	ptr = p;
	get_hit(ptr, PL);
}

void	init_light(t_vec3 *vec, double ray)
{
	t_light		*l;
	void		*ptr;

	l = magic_malloc(sizeof(t_sphere));
	l->center = vec;
	printv(*l->center);
	l->radius = ray;
	l->color = new_vec(1, 1, 1);
	ptr = l;
	get_hit(ptr, L);
}
