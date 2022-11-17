/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/11/16 17:52:21 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define MINIRT_H


typedef struct s_vec
{
	double e[3];
}				t_vec;

typedef t_vec t_point;
typedef t_vec t_color;

typedef struct s_ray
{
	t_vec	orig;
	t_vec	dir;
}				t_ray;

typedef struct s_cam
{
	double	aspect_ratio;
	int		image_width;
	int		image_height;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_point	*origin;
	t_vec	horizontal;
	t_vec	vertical;
	t_point	*lower_left_corner;
}				t_cam;

typedef struct s_img
{
	void	*i;
	void	*a;
	int		b;
	int		l;
	int		e;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	i;
	int		cur_img;
	t_cam	cam;
}				t_data;

typedef struct s_sphere
{
	t_point	center;
	double	radius;
}				t_sphere;

typedef struct s_record
{
	t_point p;
	t_vec	normal;
	double	t;
 	double	t_min;
	double	t_max;
	int		front_face;
}				t_record;

typedef struct s_hit_lst
{
	struct s_hit_lst	*next;
	void				*object;
	int					bolo;
}				t_hit_lst;
#endif 
