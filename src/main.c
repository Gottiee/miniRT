/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/20 18:20:06 by gmansuy          ###   ########.fr       */
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
	init_sphere(new_vec(0, 0, -1), 0.3);
	init_sphere(new_vec(-0.8, 0, -1), 0.3);
	// init_sphere(new_vec(0, -100.5, -0.5), 100);
	// init_sphere(new_vec(0, -10.5, -0.5), 10);
	mlx_center(&data);
	return (0);
}
