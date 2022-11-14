/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:46:40 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/14 16:29:31 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/*Crée un nouveau vecteur qui est l'addition des vecteurs u et v*/
t_vec	*plus(t_vec *u, t_vec *v)
{
	t_vec *new;

	new = magic_malloc(sizeof(t_vec));
	new->e[0] = u->e[0] + v->e[0];
	new->e[1] = u->e[1] + v->e[1];
	new->e[2] = u->e[2] + v->e[2];
	return (new);
}

/*Crée un nouveau vecteur qui est la soustraction des vecteurs u et v*/
t_vec	*minus(t_vec *u, t_vec *v)
{
	t_vec *new;

	new = magic_malloc(sizeof(t_vec));
	new->e[0] = u->e[0] - v->e[0];
	new->e[1] = u->e[1] - v->e[1];
	new->e[2] = u->e[2] - v->e[2];
	return (new);
}

/*Crée un nouveau vecteur qui est la mutiplication des vecteurs u et v*/
t_vec	*mult_vec(t_vec *u, t_vec *v)
{
	t_vec *new;

	new = magic_malloc(sizeof(t_vec));
	new->e[0] = u->e[0] * v->e[0];
	new->e[1] = u->e[1] * v->e[1];
	new->e[2] = u->e[2] * v->e[2];
	return (new);
}

/*Crée un nouveau vecteur qui est la mutiplication de u par la constante t*/
t_vec	*mult_const(t_vec *u, const double t)
{
	t_vec *new;

	new = magic_malloc(sizeof(t_vec));
	new->e[0] = u->e[0] * t;
	new->e[1] = u->e[1] * t;
	new->e[2] = u->e[2] * t;
	return (new);
}

/*Crée un nouveau vecteur qui est la division de u par la constante t*/
t_vec	*div_const(t_vec *u, const double t)
{
	return (mult_const(u, 1 / t));
}
