/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/11/14 15:30:40 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>

# define WINDOW_H 1080
# define WINDOW_W 1920
# include "../libft/include/libft.h"
# include "struct.h"

/*          --- Fonction qui gere la lib Mlx ---     */

/*Fichier: mlx_fonction.c*/
void	mlx_center(void);

/*          --- Classe vector ---     */

/*Fichier: vector_class.c*/
void	plus_equal(t_vec *u, t_vec *v);
void	mult_equal(t_vec *u, double t);
void	div_equal(t_vec *u, double t);
double	length_squared(t_vec *u);
double	length(t_vec *u);
/*Fichier: vector_utility.c*/
t_vec	*plus(t_vec *u, t_vec *v);
t_vec	*minus(t_vec *u, t_vec *v);
t_vec	*mult_vec(t_vec *u, t_vec *v);
t_vec	*mult_const(t_vec *u, const double t);
t_vec	*div_const(t_vec *u, const double t);
/*Fichier: vector_utility2.c*/
void	printv(t_vec *u);
double	dot(t_vec *u, t_vec *v);
t_vec	*cross(t_vec *u, t_vec *v);
t_vec	*unit_vector(t_vec *v);
void	init_vec(t_vec *u, int x, int y, int z);

#endif 
