/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:19:57 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/14 15:42:54 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/*Print les valeurs x, y, z du vecteur u*/
void	printv(t_vec *u)
{
	printf("x:%f y:%f z:%f\n", u->e[0], u->e[1], u->e[2]);
}

/*Résultat d'une multiplication des vecteurs u et v*/
double	dot(t_vec *u, t_vec *v)
{
	return (u->e[0] * v->e[0] + u->e[1] * v->e[1] + u->e[2] * v->e[2]);
}

/*??????????????????*/
t_vec	*cross(t_vec *u, t_vec *v)
{
	t_vec *new;

	new = magic_malloc(sizeof(t_vec));
	new->e[0] = u->e[1] * v->e[2] - u->e[2] * v->e[1];
	new->e[1] = u->e[2] * v->e[0] - u->e[0] * v->e[2];
	new->e[2] = u->e[0] * v->e[1] - u->e[1] * v->e[0];
	return (new);
}

/*Crée un nouveau vecteur qui est la mutiplication de u par la constante t*/
t_vec	*unit_vector(t_vec *v)
{
	return (div_const(v, length(v)));
}

/*Crée un nouveau vecteur avec des valeurs arbitraires*/
void	init_vec(t_vec *u, int x, int y, int z)
{
	u->e[0] = x;
	u->e[1] = y;
	u->e[2] = z;
}
