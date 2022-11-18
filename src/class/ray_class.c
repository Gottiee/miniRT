/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:57:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/18 13:39:18 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_ray	new_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray new;
	
	new.orig = origin;
	new.dir = direction;
	return (new);
} 

/*Modifie r.dir en additionant r.orig a t*r.dir*/
t_point	at(t_ray r, double t)
{

//  point3 at(double t) const {
//             return orig + t*dir;
//         }

	return (plus(r.orig, mult(r.dir, t)));

	// mult_equal(&r->dir, t);
	// r->dir.x = r->orig.x + r->dir.x;
	// r->dir.y = r->orig.y + r->dir.y;
	// r->dir.z = r->orig.z + r->dir.z;
}
