/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:28:42 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/20 15:27:08 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

// int	check_extension(char *file)
// {
// 	int i;

// 	i = -1;
// 	while (file[++i] && file[i] != '.');
// 	if (file[i] != '.')
// 		return (0);
// 	i ++;
// 	if (!ft_strncmp(file + i, "rt", 3))
// 		return (1);
// 	return (0);
// }

// int	loop_objects(char *file)
// {
// 	int fd;

// 	if (!check_extension(file))
// 	{
// 		printf("Bad extention, check the name file\n");
// 		return (0);
// 	}
// 	fd = open(file, O_RDONLY);
// 	if (!object(fd))
// 	{
// 		magic_free();
// 		return (0);
// 	}
// 	//init_sphere(new_vec(0, 0, -1), 0.5);
// 	// init_sphere(new_vec(0.5, 0, -1), 0.2);
// 	// init_sphere(new_vec(0, -100.5, -0.5), 100);
// 	// init_sphere(new_vec(1, 0, -1), 0.2);
// 	// init_sphere(new_vec(1.1, 0, -1), 0.2);
// 	close(fd);
// 	return (1);
// }
