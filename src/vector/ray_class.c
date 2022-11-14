/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:57:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/14 16:30:01 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_ray	*init_ray(t_vec *origin, t_vec *direction)
{
	t_ray *new;
	
	new = magic_malloc(sizeof(t_ray));
	new->orig = origin;
	new->dir = direction;
	return (new);
} 

t_vec	*at(t_ray *r, double t)
{
	return (plus(r.orig, mult_const(r.dir, t)));
} 

