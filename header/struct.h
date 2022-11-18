/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/11/18 18:18:28 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define MINIRT_H


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
}				t_sphere;

typedef struct s_record
{
	t_point p;
	t_vec3	normal;
	t_color	sphere_color;
	double	t;
	double	light_level;
	int		front_face;
}				t_record;

typedef struct s_hit_lst
{
	struct s_hit_lst	*next;
	void				*object;
	int					bolo;
}				t_hit_lst;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	i;
	t_cam	cam;
	int		render_image;
	//moves
	int		left;
	int		right;
	int		up;
	int		down;
	int		far;
	int		close;
}				t_data;

#endif 
