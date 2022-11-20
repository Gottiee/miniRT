/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:59:04 by eedy              #+#    #+#             */
/*   Updated: 2022/11/20 15:26:19 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

// void	string_move(char *line)
// {
// 	while (*line && (*line != ' ' && *line != '\t'))		
// 		line ++;	
// 	while (*line && (*line == ' ' || *line == '\t'))		
// 		line ++;
// }

// double	get_decimal(char *line, int i)
// {
// 	double left;		
// 	double right;

// 	left = ft_atoi(line);
// 	printf("%f\n", left);
// 	while (*line && (*line > '0' || *line < 9))
// 		line ++;
// 	if (!*line)
// 	{
// 		printf("Error\nLine %d isn't complet\n", i);
// 		return (ERROR);
// 	}
// 	if (*line == '.')
// 	{
// 		line ++;
// 		right = ft_atoi(line);
// 		printf("%f\n", right);
// 		if (right < 0)
// 		printf("Error\nLine %d float number problem\n", i);
// 		while (right > 1)
// 			right *= 0.1;
// 	}
// 	else
// 		right = 0;
// 	string_move(line);
// 	return (left + right);
// }

// int get_vector(char *line, int i, t_color *color)
// {
	
// }

// int	lex_A(t_lex *lex, char *line, int i)
// {
// 	lex->ratio = get_decimal(line, i);
// 	if (lex->ratio == ERROR)
// 		return (0);
// 	if (!*line)
// 	{
// 		printf("Error\nLine %d isn't complet\n", i);
// 		return (0);
// 	}
// 	if (!get_vector(line, i, &lex->color))
// 		return (0);
// 	return (1);
// }

// int	lex_C(t_lex *lex, char *line, int i)
// {
// 	(void)lex;
// 	(void)line;
// 	(void)i;
// 	return (1);
// }

// int	lex_L(t_lex *lex, char *line, int i)
// {
// 	(void)lex;
// 	(void)line;
// 	(void)i;
// 	return (1);
// }

// int	lex_objects(t_lex *lex, char *line, int i)
// {
// 	(void)lex;
// 	(void)line;
// 	(void)i;
// 	return (1);
// }
