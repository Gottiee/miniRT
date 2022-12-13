/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:25:03 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/13 14:41:05 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	into_radius(t_vec3 *rslt, t_vec3 base, double radius)
{
	if ((radius + 0.012) - norme(minus(base, *rslt)) <= 0)
		return (0);
	return (1);
}

void	init_plan(t_plane *plan, t_cyl *cl, double normal_dir)
{
	if (normal_dir == -1)
		eq_vector(&plan->center, cl->center);
	else
		eq_vector(&plan->center, plus(cl->center, \
		mult(normalize(cl->orient), cl->height)));
	eq_vector(&plan->orient, \
	mult(normalize(cl->orient), normal_dir));
	eq_vector(&plan->color, cl->color);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
