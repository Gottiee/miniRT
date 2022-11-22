/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/11/22 16:31:27 by eedy             ###   ########.fr       */
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
# include <time.h>
# include <unistd.h>
//IMAGE
# define WINDOW_H 560
# define WINDOW_W 720

# define ERROR -29999
# define NONE 0
# define SPHERE 1
# define A 2
# define C 3
# define L 4
# define SP 5
# define PL 6
# define CY 7

# include "../libft/include/libft.h"
# include "class.h"
# include "draw.h"

enum e_alpha {_A, _B, _C};

/*         --- UTILS ---     */

/*Fichier: mlx_fonction.c*/
void		mlx_center(t_data *data);
/*Fichier : move.c*/
void		move(int keysym, t_data *data);
void		init_move(t_data *data);
int			key_release(int keysym, t_data *data);
void		move_light(t_data *data);
void		move_cam(t_data *data);
/*Fichier : get_data.c*/
t_data		*get_data(void);
/*Fichier : animation.c*/
void	animation(t_data *data);

/*			--- RENDER ---	*/

/*Fichier : display.c*/
void		img_pix_put(t_img *img, int x, int y, int color);
int			hexa(t_color col);
double		clamp(double x, double min, double max);
/*Fichier: render.c*/
int			render(t_data *data);
/*Fichier: object_renderer.c*/
int			hit_global(t_ray r, t_record *rec, t_point light);
void		init_pointer(int (*hit[2])(t_record *rec, t_ray r, t_vec2 limit, t_point light));
/*Fichier: sphere.c*/
int			hit_sphere(t_record *rec, t_ray r, t_vec2 limit, t_point light);
double		discriminent(t_ray r, t_sphere s, double *p);
/*Fichier: light.c*/
int			hit_light(t_record *rec, t_ray r, t_vec2 limit, t_point light);

/*Fichier: shadow_render.c*/
void		shadow_render(t_record *rec, t_point light);

/*			--- OBJECTS -- 	*/

/*Fichier: init_objects.c*/
void		init_sphere(t_vec3 vec, double ray, t_color color);
void		init_light(t_vec3 *vec, double ray);
/*Fichier: hittable_list.c*/
t_hit_lst	*get_hit(void *obj, int type);
/*Fichier: loop_objects.c*/
int			loop_objects(char *file);
/*Fichier: lexeur.c*/
int			object(int fd);
/*Fichier: lexeur_object.c*/
int			lex_A(t_lex *lex, char *line, int i);
int			lex_L(t_lex *lex, char *line, int i);
int			lex_C(t_lex *lex, char *line, int i);
int			lex_objects(t_lex *lex, char *line, int i);
#endif 
