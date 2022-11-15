/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:46:40 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/15 14:29:40 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/*Additionne le vecteur v au vecteur u*/
void	plus_equal(t_vec *u, t_vec *v)
{
	u->e[0] += v->e[0];
	u->e[1] += v->e[1];
	u->e[2] += v->e[2];
}

/*Multiplie le vecteur u par t*/
void	mult_equal(t_vec *u, double t)
{
	u->e[0] *= t;
	u->e[1] *= t;
	u->e[2] *= t;
}

/*Divise le vecteur u par t*/
void	div_equal(t_vec *u, double t)
{
	mult_equal(u, 1 / t);
}

/*Taille du vecteur 'u' au carré*/
double	length_squared(t_vec *u)
{
	return (u->e[0] * u->e[0] + u->e[1] * u->e[1] + u->e[2] * u->e[2]);
}

/*Taille du vecteur 'u'*/
double	length(t_vec *u)
{
	return (sqrt(length_squared(u)));
}
