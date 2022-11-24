/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:13:09 by eedy              #+#    #+#             */
/*   Updated: 2022/11/23 13:24:52 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"
/*
void	string_move(char *line)
{
	while (*line && (*line != ' ' && *line != '\t' && *line != ','))		
		line ++;	
	while (*line && (*line == ' ' || *line == '\t'))		
		line ++;
}

double	get_decimal(char *line, int i)
{
	double left;		
	double right;

	left = ft_atoi(line);
	printf("%f\n", left);
	while (*line && (*line > '0' || *line < 9))
		line ++;
	if (!*line)
	{
		printf("Error\nLine %d isn't complet\n", i);
		return (ERROR);
	}
	if (*line == '.')
	{
		line ++;
		right = ft_atoi(line);
		printf("%f\n", right);
		if (right < 0)
		printf("Error\nLine %d float number problem\n", i);
		while (right > 1)
			right *= 0.1;
	}
	else
		right = 0;
	string_move(line);
	return (left + right);
}

int get_vector(char *line, int i, t_color *color)
{
	color->x = get_decimal(line, i);
	if (!*line || *line != ',')
	{
		printf("Vector none complet line %d\n", i);
		return (0);
	}
	color->y = get_decimal(line, i);
	if (!*line || *line != ',')
	{
		printf("Vector none complet line %d\n", i);
		return (0);
	}
	color->z = get_decimal(line, i);
	return (1);
}*/
