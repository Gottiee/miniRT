/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:19:57 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/25 14:12:41 by gmansuy          ###   ########.fr       */
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