/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:06:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/15 14:20:21 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_cylinder(t_lex lex)
{
	t_cyl		*s;
	void		*ptr;

	s = magic_malloc(sizeof(t_cyl));
	if (!s)
	{
		magic_free();
		exit(1);
	}
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
	if (!s)
	{
		magic_free();
		exit(1);
	}
	s->center = lex.coord;
	s->color = unit_vector(divis(lex.color, 255));
	s->radius = lex.radius;
	ptr = s;
	get_hit(ptr, SP);
}

void	init_plane2(t_lex lex)
{
	t_plane	*p2;
	void	*ptr2;

	p2 = magic_malloc(sizeof(t_plane));
	if (!p2)
	{
		magic_free();
		exit(1);
	}
	p2->center = lex.coord;
	p2->color = unit_vector(divis(lex.color, 255));
	p2->orient = mult(lex.orient, -1);
	ptr2 = p2;
	get_hit(ptr2, PL);
}

void	init_plane(t_lex lex)
{
	t_plane	*p;
	void	*ptr;

	p = magic_malloc(sizeof(t_plane));
	if (!p)
	{
		magic_free();
		exit(1);
	}
	p->center = lex.coord;
	p->color = unit_vector(divis(lex.color, 255));
	p->orient = lex.orient;
	ptr = p;
	get_hit(ptr, PL);
	init_plane2(lex);
}
