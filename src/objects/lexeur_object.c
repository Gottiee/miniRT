/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:59:04 by eedy              #+#    #+#             */
/*   Updated: 2022/11/28 10:55:43 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	isnt_complet(int i, int bool)
{
	if (bool == 0)
	{
		printf("Error\nLine %d isn't complet\n", i);
		return (0);
	}
	else if (bool == 1)
	{
		printf("Error\n Line %d too many arguments\n", i)	;
		return (0);
	}
	return (0);
}

int	lex_A(t_lex *lex, char *line, int i)
{
	lex->ratio = get_decimal(&line, i);
	if (lex->ratio == ERROR)
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	if (!get_vector(&line, i, &lex->color))
		return (0);
	if (*line)
		return (isnt_complet(i, 1));
	return (1);
}

int	lex_C(t_lex *lex, char *line, int i)
{
	if (!get_vector(&line, i, &lex->coord))
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	if (!get_vector(&line, i, &lex->orient))
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	lex->fov = atoi(line);
	line = string_move(line);
	if (*line)
		return (isnt_complet(i, 1));
	return (1);
}

int	lex_L(t_lex *lex, char *line, int i)
{
	if (!get_vector(&line, i, &lex->coord))
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	lex->ratio = get_decimal(&line, i);
	if (!*line)
		return (isnt_complet(i, 0));
	if (!get_vector(&line, i, &lex->color))
		return (0);
	if (*line)
		return (isnt_complet(i, 1));
	return (1);
}

int	lex_objects(t_lex *lex, char *line, int i)
{
	if (lex->type == SP)
		if (!lex_SP(lex, line, i))
			return (0);
	if (lex->type == PL)
		if (!lex_PL(lex, line, i))
			return (0);
	if (lex->type == CY)
		if (!lex_CY(lex, line, i))
			return (0);
	return (1);
}
