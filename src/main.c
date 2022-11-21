/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/21 15:20:09 by gmansuy          ###   ########.fr       */
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
	init_sphere(new_vec(0, 0, -1), 0.5, new_vec(1, 0, 0));
	// init_sphere(new_vec(0, -1, -1), 0.5);
	// init_sphere(new_vec(-1, 1, -1), 0.3);
	init_light(&data.cam.light, 0.1);
	// init_sphere(new_vec(0, -100.5, -0.5), 100);
	// init_sphere(new_vec(0, -1.3, -0.5), 1);
	mlx_center(&data);
	return (0);
}
