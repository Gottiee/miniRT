/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/11/18 15:41:23 by gmansuy          ###   ########.fr       */
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
# include <float.h>

//IMAGE
# define WINDOW_H 1080
# define WINDOW_W 1920

# define SPHERE 1

# include "../libft/include/libft.h"
# include "class.h"

/*         --- UTILS ---     */

/*Fichier: mlx_fonction.c*/
void		mlx_center(t_data data);
/*Fichier : convert_rgb.c*/
void		img_pix_put(t_img *img, int x, int y, int color);
int			hexa(t_color col);
/*Fichier : move.c*/
void		move(int keysym, t_data *data);

/*			--- RENDER ---	*/

/*Fichier: render.c*/
int			render(t_data *data);
/*Fichier: object_renderer.c*/
int			hit_global(t_ray r, t_record *rec, double t_min, double t_max);
/*Fichier: sphere.c*/
int			hit_sphere(t_record *rec, t_ray r, t_sphere *s, t_vec2 limit);

/*			--- OBJECTS -- 	*/

/*Fichier: init_objects.c*/
void		init_sphere(t_vec3 vec, double ray);
/*Fichier: hittable_list.c*/
t_hit_lst	*get_hit(void *obj);
/*Fichier: loop_objects.c*/
void		loop_objects();
#endif 
