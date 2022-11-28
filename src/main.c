/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/28 16:35:38 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int	main(int argc, char **argv)
{	
	t_data data;
	(void)argc;
	(void)argv;
	(void)data;

	if (argc != 2)
		return (printf("Error\nInvalid args\n"), 1);
	loop_objects(argv[1]);
	init_cam(&data.cam, (double)WINDOW_W / (double)WINDOW_H, 2.0, 2.0);
	// init_light(&data.cam.light, 0.1);
	// init_plane(new_vec(0, 0, -2), new_vec(0, 0, 1), unit_vector(new_vec(0, 0, -1)));
	// init_plane(new_vec(0, 0, -1), new_vec(0, 1, 0), unit_vector(new_vec(-0.5, -1, -1)));
	// init_sphere(new_vec(0, 0, 0), 0.5, new_vec(1, 0, 0));
	// init_sphere(new_vec(0, 0, 0), 0.5, new_vec(0, 1, 0));
	// init_cylinder(new_vec(0, -3, -1), new_vec(0, 0.5, 0),
	// 		new_vec(0.5, 0.2, 0.3), new_vec2(0.5, 10));
	mlx_center(&data);
	printf("OK\n");
	return (0);
}
