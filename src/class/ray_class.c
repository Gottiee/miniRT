/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_class.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:57:52 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/17 13:39:31 by gmansuy          ###   ########.fr       */
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

/*Modifie r.dir en additionant r.orig a t*r.dir*/
void	at(t_ray *r, double t)
{
	mult_equal(&r->dir, t);
	r->dir.e[0] = r->orig.e[0] + r->dir.e[0];
	r->dir.e[1] = r->orig.e[1] + r->dir.e[1];
	r->dir.e[2] = r->orig.e[2] + r->dir.e[2];
}
