/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:17 by eedy              #+#    #+#             */
/*   Updated: 2022/11/14 15:21:41 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define MINIRT_H

// enum e_coord {X, Y ,Z};

typedef struct s_vec
{
	double e[3];
}				t_vec;

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
}				t_data;

/*          --- Fonction qui gere la lib Mlx ---     */

/*Fichier: mlx_fonction.c*/
void	mlx_center(void);

#endif 
