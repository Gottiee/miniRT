/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/11/23 15:36:01 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
#define CLASS_H

# include "struct.h"

/*          --- ClASS---     */

/*Fichier: vector_class.c*/
void	vec(t_vec3 *u, double x, double y, double z);
t_vec3	plus_equal(t_vec3 *u, t_vec3 *v);
t_vec3	min_equal(t_vec3 *u, t_vec3 *v);
t_vec3	mult_equal(t_vec3 *u, double t);
t_vec3	div_equal(t_vec3 *u, double t);
double	length_squared(t_vec3 *u);
double	length(t_vec3 *u);
/*Fichier: vector_utility.c*/
t_vec3	plus(t_vec3 u, t_vec3 v);
t_vec3	minus(t_vec3 u, t_vec3 v);
t_vec3	mult_vec(t_vec3 u, t_vec3 v);
t_vec3	div_vec(t_vec3 u, t_vec3 v);
t_vec3	mult(t_vec3 u, const double t);
t_vec3	divis(t_vec3 u, const double t);
/*Fichier: vector_utility2.c*/
void	printv(t_vec3 u);
double	dot(t_vec3 u, t_vec3 v);
t_vec3	cross(t_vec3 u, t_vec3 v);
t_vec3	unit_vector(t_vec3 v);
t_vec3	new_vec(double x, double y, double z);
t_vec3	max(t_vec3 v1, t_vec3 v2);
/*Fichier: ray_class.c*/
t_ray	new_ray(t_vec3 origin, t_vec3 direction);
t_point	at(t_ray r, double t);
/*Fichier: cam_class.c*/
void	init_cam(t_cam *cam, double ratio, double view_height, double foc_len);
t_point	*get_light();
void	set_llc(t_cam *cam, double focal);

#endif 
