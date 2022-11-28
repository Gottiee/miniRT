/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:13:09 by eedy              #+#    #+#             */
/*   Updated: 2022/11/28 10:55:56 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

char	*string_move(char *line)
{
	while (*line && (*line != ' ' && *line != '\t' && *line != ','))		
		line ++;	
	while (*line && (*line == ' ' || *line == '\t'))		
		line ++;
	return (line);
}

double	get_decimal(char **line, int i)
{
	double left;		
	double right;

	left = ft_atoi(*line);
	while (**line && !(**line >= '0' && **line <= '9'))
		(*line) ++;
	if (!**line)
	{
		printf("Error\nLine %d isn't complet\n", i);
		return (ERROR);
	}
	if (**line == '.')
	{
		(*line) ++;
		right = ft_atoi(*line);
		if (right < 0)
		printf("Error\nLine %d float number problem\n", i);
		while (right > 1)
			right *= 0.1;
	}
	else
		right = 0;
	*line = string_move(*line);
	return (left + right);
}

int get_vector(char **line, int i, t_color *color)
{
	color->x = get_decimal(line, i);
	if (!**line || **line != ',')
	{
		printf("Error\nVector none complet line %d\n", i);
		return (0);
	}
	color->y = get_decimal(line, i);
	if (!**line || **line != ',')
	{
		printf("Error\nVector none complet line %d\n", i);
		return (0);
	}
	color->z = get_decimal(line, i);
	*line = string_move(*line);
	return (1);
}
