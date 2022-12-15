/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/12/14 13:57:37 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H


typedef struct s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;


typedef t_vec3 t_point;
typedef t_vec3 t_color;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}				t_ray;

typedef struct s_cam
{
	t_vec3	horizontal;
	t_vec3	vertical;
	t_point	origin;
	t_point	lower_left_corner;
	t_point	light;
	double	fov;
	double	focal;
	t_vec3	lookfrom;	
	t_vec3	lookat;

	double		ratio;
	double		theta;
	double		h;
	t_vec3		vup;		
    t_vec3		w;
    t_vec3		u;
    t_vec3		v;
	double		view_width;
	double		view_height;
}				t_cam;

typedef struct s_matrix
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	forward;
	t_vec3	cam;
}	t_matrix;

typedef struct s_eqn
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
	double	t;
}	t_eqn;

typedef struct s_img
{
	void	*i;
	void	*a;
	int		b;
	int		l;
	int		e;
}				t_img;


typedef struct s_sphere
{
	t_point	center;
	double	radius;
	t_color	color;
	
}				t_sphere;

typedef struct s_cyl
{
	t_point	center;
	double	radius;
	double	height;
	t_color	color;
	t_vec3	orient;
	int		inter_code;
}				t_cyl;

typedef struct s_circle
{
	t_point	center;
	double	radius;
	t_color	color;
	t_vec3	orient;
}				t_circle;

typedef struct s_plane
{
	t_point	center;
	t_color	color;
	t_vec3	orient;
	
}				t_plane;

typedef struct s_light
{
	t_point	*center;
	double	radius;
	double	ratio;
	t_color	color;
}				t_light;

typedef struct s_ambiant
{
	double	ratio;
	t_color	color;
}				t_ambiant;

typedef struct s_record
{
	t_point 	hit_point;
	t_vec3		normal;
	void		*closest;
	double		t;
	double		light_level;
	int			obj_id;
	t_color		color;
	int			type;
	double		discr;
	int			light;
}				t_record;

typedef struct s_hit_lst
{
	struct s_hit_lst	*next;
	void				*object;
	int					id;
	int					type;
}				t_hit_lst;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	i;
	t_cam	cam;
	int		render_image;
	int		disp_normals;
	t_point	light;
	int		left;
	int		right;
	int		up;
	int		down;
	int		far;
	int		close;
	int		animation;
}				t_data;

typedef struct s_lex
{
	int 		type;
	double		ratio;
	t_color		color;
	t_vec3		coord;
	t_vec3		orient;
	int			fov;
	double		radius;
	double		height;
	int			nbr_line;
	int			verif[8];
}				t_lex;

typedef struct s_spe
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	root;
	t_ray	tmp;
}				t_spe;

#endif
