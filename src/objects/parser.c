/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:25:53 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/29 15:16:05 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	verify_line(char *line, int line_nbr)
{
	while (ft_isalpha(*line))
		line ++;
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != '.' && *line != ',' 
			&& *line != ' ' && *line != '\n' && *line != '-')
			return (printf("Error\nOn line %d: Invalid input '%c'\n",
				line_nbr, *line), 0);
		line ++;
	}
	return (1);
}

int	in_range(double input, double min, double max)
{
	// printf("input : %f\n", input);
	return (input >= min && input <= max);
}

int	verify_vec(t_vec3 u, double min, double max)
{
	return ((in_range(u.x, min, max) && in_range(u.y, min, max)
		&& in_range(u.z, min, max)));
}

int	parser(t_lex lex)
{
	int	ratio;
	int	color;
	int	orient;
	int	fov;
	
	// printf("%d\n", lex.type);
	ratio = 1;
	color = 1;
	orient = 1;
	if (lex.type == L || lex.type == A)
		ratio = in_range(lex.ratio, 0, 1.0);
	if (lex.type != C)
		color = verify_vec(lex.color, 0, 255);
	if (lex.type == C || lex.type == CY || lex.type == PL)
		orient = verify_vec(lex.orient, -1.0, 1.0);
	if (lex.type == C)
		fov = in_range(lex.fov, 0, 180);
	return ((ratio && orient && color && fov));
}