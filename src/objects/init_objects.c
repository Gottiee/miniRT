/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:06:43 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/21 13:56:12 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_sphere(t_vec3 vec, double ray)
{
	t_sphere	*s;
	void		*ptr;

	s = magic_malloc(sizeof(t_sphere));
	s->center = vec;
	s->radius = ray;
	ptr = s;
	get_hit(ptr, SP);
}

void	init_light(t_vec3 *vec, double ray)
{
	t_light		*l;
	void		*ptr;

	l = magic_malloc(sizeof(t_sphere));
	l->center = vec;
	printv(*l->center);
	l->radius = ray;
	// l->color = new_vec(0.5, 0.5, 0.5);
	ptr = l;
	get_hit(ptr, L);
}