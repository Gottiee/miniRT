/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/05 13:21:50 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int	main(int argc, char **argv)
{	
	t_data	data;
	t_light	*l;

	if (argc != 2)
		return (printf("Error\nInvalid args\n"), 1);
	if (!loop_objects(argv[1]))
		return (2);
	l = get_light();
	data.light = *l->center; //marche pas
	//data.light = mult(new_vec(0, -1, 0.5), -1);
	mlx_center(&data);
	printf("OK\n");
	return (0);
}
