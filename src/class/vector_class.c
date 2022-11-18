/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_class.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:46:40 by gmansuy           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/17 13:25:34 by gmansuy          ###   ########.fr       */
=======
/*   Updated: 2022/11/17 20:05:59 by marvin           ###   ########.fr       */
>>>>>>> 0ddaeae0c8b5e994027a4416af4aef8a89c29574
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	vec(t_vec *u, double x, double y, double z)
{
	u->e[0] = x;
	u->e[1] = y;
	u->e[2] = z;
}

/*Additionne le vecteur v au vecteur u*/
t_vec	plus_equal(t_vec *u, t_vec *v)
{
	u->e[0] += v->e[0];
	u->e[1] += v->e[1];
	u->e[2] += v->e[2];
	return (*u);
}

/*Soustrait le vecteur v au vecteur u*/
t_vec	min_equal(t_vec *u, t_vec *v)
{
	u->e[0] -= v->e[0];
	u->e[1] -= v->e[1];
	u->e[2] -= v->e[2];
	return (*u);
}

/*Multiplie le vecteur u par t*/
t_vec	mult_equal(t_vec *u, double t)
{
	u->e[0] *= t;
	u->e[1] *= t;
	u->e[2] *= t;
	return (*u);
}

/*Divise le vecteur u par t*/
t_vec	div_equal(t_vec *u, double t)
{
	mult_equal(u, 1 / t);
	return (*u);
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
