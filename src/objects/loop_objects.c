/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:28:42 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/15 13:59:12 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	check_extension(char *file)
{
	int	i;

	i = -1;
	while (file[++i] && file[i] != '.')
	{
	}
	if (file[i] != '.')
		return (0);
	i ++;
	if (!ft_strncmp(file + i, "rt", 3))
		return (1);
	return (0);
}

int	loop_objects(char *file)
{
	int	fd;

	if (!check_extension(file))
	{
		printf("Error\nBad extention, check the file name\n");
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nBad file name\n"), 0);
	if (!object(fd))
	{
		magic_free();
		return (0);
	}
	close(fd);
	return (1);
}
