/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:25:53 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/28 10:46:15 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	in_range(double input, double min, double max)
{
	return (input >= min && input <= max);
}

int	verify_vec(t_vec3 u, double min, double max)
{
	return (in_range(u.x, min, max) && in_range(u.y, min, max)
		&& in_range(u.z, min, max));
}

int	verify_inputs(t_lex lex)
{
	in_range(lex.ratio, 0, 1);
	verify_vec(lex.color, 0, 255);
	verify_vec(lex.vec, -1, 1);
	return (0);
}

int	parser(t_lex lex)
{
	(void)lex;
	verify_inputs(lex);
	return (0);
}