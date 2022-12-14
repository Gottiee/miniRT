/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/14 14:02:48 by eedy             ###   ########.fr       */
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
	data.light = *l->center;
	mlx_center(&data);
	return (0);
}
