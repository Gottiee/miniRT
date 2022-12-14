/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:19:57 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/14 13:50:57 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_vec3	normalize(t_vec3 v1)
{
	return (mult(v1, 1 / norme(v1)));
}

double	scalaire_product(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	norme(t_vec3 v1)
{
	return (sqrtf(scalaire_product(v1, v1)));
}

void	eq_vector(t_vec3 *v1, t_vec3 v2)
{
	v1->x = v2.x;
	v1->y = v2.y;
	v1->z = v2.z;
}

/*Crée un nouveau vecteur qui est la division de u par la constante t*/
t_vec3	divis(t_vec3 u, const double t)
{
	return (mult(u, 1 / t));
}
