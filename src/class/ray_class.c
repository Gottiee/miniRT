/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:57:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/15 17:56:39 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_ray	*init_ray(t_vec *origin, t_vec *direction)
{
	t_ray *new;
	
	new = magic_malloc(sizeof(t_ray));
	printf("init_ray malloc!\n");
	if (!new)
		exit (0);
	new->orig = *origin;
	new->dir = *direction;
	return (new);
} 

// t_vec	*at(t_ray *r, double t)
// {
// 	return (plus(r->orig, mult_const(r->dir, t)));
// } 

