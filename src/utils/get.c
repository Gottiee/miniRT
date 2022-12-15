/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:55:49 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/14 13:33:15 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

t_cam	*get_cam(void)
{
	static t_cam	cam;

	return (&cam);
}

t_ambiant	*get_amb(void)
{
	static t_ambiant	amb;

	return (&amb);
}

t_light	*get_light(void)
{
	static t_light	light;

	return (&light);
}
