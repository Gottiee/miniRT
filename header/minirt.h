/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/12/13 11:54:31 by gmansuy          ###   ########.fr       */
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
# define CE 1

# include "../libft/include/libft.h"
# include "class.h"

enum e_alpha {_A, _B, _C, OC};

/*         --- UTILS ---     */

/*Fichier: mlx_fonction.c*/
void		mlx_center(t_data *data);
/*Fichier : move.c*/
void		move(int keysym, t_data *data);
void		init_move(t_data *data);
int			key_release(int keysym, t_data *data);
void		move_light(t_data *data);
void		move_cam(t_data *data);
/*Fichier : get.c*/
t_cam		*get_cam(void);
t_light		*get_light(void);
t_ambiant		*get_amb(void);
/*Fichier : animation.c*/
void		animation(t_data *data);
/*Fichier : minmax.c*/
double	ft_min(double a, double b);
double	ft_max(double a, double b);

/*			--- RENDER ---	*/

/*Fichier : display.c*/
void		img_pix_put(t_img *img, int x, int y, int color);
int			hexa(t_color col);
double		clamp(double x, double min, double max);
/*Fichier: render.c*/
int			render(t_data *data);
/*Fichier: object_renderer.c*/
t_vec3  	hit_global(t_ray r, double *t_min, t_hit_lst **obj, int shad);

/*Fichier: shadow_render.c*/
t_color	    shadow_render(t_vec3 hit_point, t_light s_light, t_hit_lst *obj, t_ray r, int n);

/*			--- INTERSECTION ---	*/

/*Fichier: plane.c*/
double	inter_plan(t_vec3 dir_pix, t_vec3 cam_o, void *plan, t_vec3 *rslt);
t_vec3	normal_pl(t_plane *pl, t_vec3 hit_point, t_vec3 cam_pos);
/*Fichier: cylinder.c*/
double	inter_cylindre(t_vec3 dir_pix, t_vec3 cam_o, void *cylindre, t_vec3 *rslt);
t_vec3	normal_cy(t_cyl *cy, t_vec3 hit_point, t_vec3 cam_pos);
/*Fichier: sphere.c*/
double	inter_light(t_vec3 dir_pix, t_vec3 cam_o, void *sphere, t_vec3 *rslt);
double	inter_sphere(t_vec3 dir_pix, t_vec3 cam_o, void *sphere, t_vec3 *rslt);
t_vec3	normal_sp(t_sphere *sp, t_vec3 hit_point, t_vec3 cam_pos);

/*			--- OBJECTS -- 	*/

/*Fichier: init_objects.c*/
void		init_sphere(t_lex lex);
void		init_light(t_lex lex);
void		init_plane(t_lex lex);
void		init_cylinder(t_lex lex);
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
int			isnt_complet(int i, int bool);
/*Fichier: lexeur_geo_obj.c*/
int 		lex_SP(t_lex *lex, char *line, int i);
int			lex_PL(t_lex *lex, char *line, int i);
int			lex_CY(t_lex *lex, char *line, int i);
/*Fichier: lexeur_util.c*/
char		*string_move(char *line);
double		get_decimal(char **line, int i);
int 		get_vector(char **line, int i, t_color *color);
/*Fichier: parser.c*/
int			parser(t_lex lex, int *verif);
int			verify_line(char *line, int line_nbr);
/*Fichier: new_object.c*/
int			new_object(t_lex lex);
void		init_circle(t_lex lex);

//utils
void	init_plan(t_plane *plan, t_cyl *cl, double normal_dir);
int		into_radius(t_vec3 *rslt, t_vec3 base, double radius);
double	max(double a, double b);
double	min(double a, double b);

#endif 
