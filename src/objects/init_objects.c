/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:06:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/06 18:11:38 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_cylinder(t_lex lex)
{
	t_cyl		*s;
	void		*ptr;

	s = magic_malloc(sizeof(t_cyl));
	s->center = lex.coord;
	s->color = unit_vector(divis(lex.color, 255));
	s->orient = lex.orient;
	s->radius = lex.radius;
	s->height = lex.height;
	ptr = s;
	get_hit(ptr, CY);
}

void	init_sphere(t_lex lex)
{
	t_sphere	*s;
	void		*ptr;

	s = magic_malloc(sizeof(t_sphere));
	s->center = lex.coord;
	s->color = unit_vector(divis(lex.color, 255));
	s->radius = lex.radius;
	ptr = s;
	get_hit(ptr, SP);
}

void	init_plane(t_lex lex)
{
	t_plane	*p;
	void	*ptr;
	
	p = magic_malloc(sizeof(t_plane));
	p->center = lex.coord;
	p->color = unit_vector(divis(lex.color, 255));
	p->orient = lex.orient;
	ptr = p;
	get_hit(ptr, PL);
}

void	init_light(t_lex lex)
{
	t_light		*l;
	void		*ptr;

	l = get_light();
	l->center = magic_malloc(sizeof(t_vec3));
	*l->center = lex.coord;
	l->radius = 0.1;
	l->ratio = lex.ratio;
	//l->color = unit_vector(divis(lex.color, 255));
	l->color = lex.color;
	ptr = l;
	get_hit(ptr, L);
}
