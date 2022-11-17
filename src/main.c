/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/17 14:15:26 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

void	init_sphere(t_vec *vec, double ray)
{
	t_sphere	*s;
	void		*ptr;

	s = magic_malloc(sizeof(t_sphere));
	s->center = *vec;
	s->radius = ray;
	ptr = s;
	get_hit(ptr);
}

int	main()
{
	init_sphere(new_vec(0, 0, -1), 0.5);
	init_sphere(new_vec(1, 0, -1), 0.2);
	init_sphere(new_vec(1.1, 0, -1), 0.2);
	init_sphere(new_vec(0, -100.5, -1), 100);
	
	mlx_center();
}
