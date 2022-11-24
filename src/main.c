/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/24 16:07:08 by eedy             ###   ########.fr       */
/*   Updated: 2022/11/24 15:11:19 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int	main(int argc, char **argv)
{	
	t_data data;
	(void)argc;
	(void)argv;
	// if (argc != 2 || !loop_objects(argv[1]))
	// 	return (1);
	init_cam(&data.cam, (double)WINDOW_W / (double)WINDOW_H, 2.0, 2.0);
	init_light(&data.cam.light, 0.1);
	// init_plane(new_vec(0, 0, -2), new_vec(0, 0, 1), unit_vector(new_vec(0, 0, -1)));
	// init_plane(new_vec(0, 0, -1), new_vec(0, 1, 0), unit_vector(new_vec(-0.5, -1, -1)));
	// init_sphere(new_vec(0, 0, 0), 10, new_vec(1, 0, 0));
	// init_sphere(new_vec(0, 0, 0), 0.5, new_vec(0, 1, 0));
	t_vec3 v = new_vec(0, 0, 0);
	v.height = 0.5;
	init_cylinder(v, 2, new_vec(0, 0, 0), new_vec(0, 0.2, 0.8));
	mlx_center(&data);
	return (0);
}
