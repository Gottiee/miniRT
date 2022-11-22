/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/11/22 14:06:49 by eedy             ###   ########.fr       */
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
	double	focal;
	t_vec3	rotate;
}				t_cam;

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

typedef struct s_light
{
	t_point	*center;
	double	radius;
	t_color	color;
}				t_light;

typedef struct s_record
{
	t_point 	hit_point;
	t_vec3		normal;
	void		*closest;
	// t_sphere	closest;
	double		t;
	double		light_level;
	int			obj_id;
	t_color		color;
	int			type;
	int 		light;
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
	//moves
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
}				t_lex;

#endif 
