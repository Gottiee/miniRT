/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:46:40 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/14 13:58:55 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	vec(t_vec3 *u, double x, double y, double z)
{
	u->x = x;
	u->y = y;
	u->z = z;
}

/*Additionne le vecteur v au vecteur u*/
t_vec3	plus_equal(t_vec3 *u, t_vec3 *v)
{
	u->x += v->x;
	u->y += v->y;
	u->z += v->z;
	return (*u);
}

/*Soustrait le vecteur v au vecteur u*/
t_vec3	min_equal(t_vec3 *u, t_vec3 *v)
{
	u->x -= v->x;
	u->y -= v->y;
	u->z -= v->z;
	return (*u);
}

/*Multiplie le vecteur u par t*/
t_vec3	mult_equal(t_vec3 *u, double t)
{
	u->x *= t;
	u->y *= t;
	u->z *= t;
	return (*u);
}

/*Divise le vecteur u par t*/
t_vec3	div_equal(t_vec3 *u, double t)
{
	mult_equal(u, 1 / t);
	return (*u);
}
