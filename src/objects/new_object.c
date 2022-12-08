/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:25:53 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/08 17:28:59 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_amb(t_lex lex)
{
	t_ambiant	*amb;
	
	amb = get_amb();
	amb->color = unit_vector(divis(lex.color, 255));
	amb->ratio = lex.ratio;
}

void	init_circle(t_lex lex)
{
	t_circle		*s;
	void			*ptr;

	s = magic_malloc(sizeof(t_circle));
	printv(lex.orient);
	s->center = lex.coord;
	s->color = unit_vector(divis(lex.color, 255));
	s->orient = lex.orient;
	s->radius = lex.radius;
	ptr = s;
	get_hit(ptr, CE);
}

int	new_object(t_lex lex)
{
	void 	(*init[8])(t_lex lex);
	
	init[A] = &init_amb;
	init[C] = &init_cam;
	init[L] = &init_light;
	init[SP] = &init_sphere;
	init[PL] = &init_plane;
	init[CY] = &init_cylinder;
	init[CE] = &init_circle;
	init[lex.type](lex);
	return (0);
}