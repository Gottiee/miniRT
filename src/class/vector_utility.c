/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:46:40 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/18 13:42:13 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/*Crée un nouveau vecteur qui est l'addition des vecteurs u et v*/
t_vec3	plus(t_vec3 u, t_vec3 v)
{
	t_vec3 new;

	new.x = u.x + v.x;
	new.y = u.y + v.y;
	new.z = u.z + v.z;
	return (new);
}

/*Crée un nouveau vecteur qui est la soustraction des vecteurs u et v*/
t_vec3	minus(t_vec3 u, t_vec3 v)
{
	t_vec3 new;
	
	new.x = u.x - v.x;
	new.y = u.y - v.y;
	new.z = u.z - v.z;
	return (new);
}

/*Crée un nouveau vecteur qui est la mutiplication des vecteurs u et v*/
t_vec3	mult_vec(t_vec3 u, t_vec3 v)
{
	t_vec3 new;

	new.x = u.x * v.x;
	new.y = u.y * v.y;
	new.z = u.z * v.z;
	return (new);
}

/*Crée un nouveau vecteur qui est la mutiplication de u par la constante t*/
t_vec3	mult(t_vec3 u, const double t)
{
	t_vec3 new;

	new.x = u.x * t;
	new.y = u.y * t;
	new.z = u.z * t;
	return (new);
}

/*Crée un nouveau vecteur qui est la division de u par la constante t*/
t_vec3	divis(t_vec3 u, const double t)
{
	return (mult(u, 1 / t));
}
