/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <eliot.edy@icloud.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:58:27 by eedy              #+#    #+#             */
/*   Updated: 2022/12/14 14:01:09 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/*Taille du vecteur 'u' au carré*/
double	length_squared(t_vec3 *u)
{
	return (u->x * u->x + u->y * u->y + u->z * u->z);
}

/*Taille du vecteur 'u'*/
double	length(t_vec3 *u)
{
	return (sqrt(length_squared(u)));
}

t_vec2	new_vec2(double x, double y)
{
	t_vec2	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_vec3	maxi(t_vec3 v1, t_vec3 v2)
{
	if (length(&v1) > length(&v2))
		return (v1);
	else
		return (v2);
}
