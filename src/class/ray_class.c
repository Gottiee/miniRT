/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:57:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/15 13:51:19 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_ray	new_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	new;

	new.orig = origin;
	new.dir = direction;
	return (new);
}

/*Modifie r.dir en additionant r.orig a t*r.dir*/
t_point	at(t_ray r, double t)
{
	return (plus(r.orig, mult(unit_vector(r.dir), t)));
}

t_point	sat(t_ray r, double t)
{
	return (plus(r.orig, mult((r.dir), t)));
}
