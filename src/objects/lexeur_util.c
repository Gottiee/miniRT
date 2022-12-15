/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:13:09 by eedy              #+#    #+#             */
/*   Updated: 2022/12/15 13:48:49 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

char	*string_move(char *line)
{
	while (*line && (*line != ' ' && *line != '\t' && *line != ','))
		line ++;
	while (*line && (*line == ' ' || *line == '\t'))
		line ++;
	if (*line == ',')
		line ++;
	return (line);
}

double	get_dec_right(char **line, int i)
{
	double	right;

	right = 0;
	if (**line == '.')
	{
		(*line)++;
		right = ft_atoi(*line);
		if (right < 0)
		{
			printf("Error\nLine %d double number problem\n", i);
			right = ERROR;
		}
		while (right >= 1)
			right *= 0.1;
	}
	return (right);
}

double	get_decimal(char **line, int i)
{
	double	left;		
	double	right;
	int		bool;

	bool = 0;
	left = ft_atoi(*line);
	if (**line == '-')
	{
		bool = 1;
		(*line)++;
	}
	while (**line && (**line >= '0' && **line <= '9'))
		(*line)++;
	if (!**line)
	{
		printf("Error\nLine %d isn't complet\n", i);
		return (ERROR);
	}
	right = get_dec_right(line, i);
	if (right == ERROR)
		return (ERROR);
	*line = string_move(*line);
	if (left >= 0 && bool == 0)
		return (left + right);
	return (left - right);
}

int	get_vector(char **line, int i, t_color *color)
{
	color->x = get_decimal(line, i);
	if (!**line)
	{
		printf("Error\nVector none complet line %d\n", i);
		return (0);
	}
	color->y = get_decimal(line, i);
	if (!**line)
	{
		printf("Error\nVector none complet line %d\n", i);
		return (0);
	}
	color->z = get_decimal(line, i);
	return (1);
}
