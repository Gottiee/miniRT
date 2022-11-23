/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:59:04 by eedy              #+#    #+#             */
/*   Updated: 2022/11/23 13:24:14 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../../header/minirt.h"

int	lex_A(t_lex *lex, char *line, int i)
{
	lex->ratio = get_decimal(line, i);
	if (lex->ratio == ERROR)
		return (0);
	if (!*line)
	{
		printf("Error\nLine %d isn't complet\n", i);
		return (0);
	}
	if (!get_vector(line, i, &lex->color))
		return (0);
	return (1);
}

int	lex_C(t_lex *lex, char *line, int i)
{
	if (!get_vector(line, i, &lex->coord))
		return (0);
	string_move(line);
	if (!*line)
	{
		printf("Error\nLine %d isn't complet\n", i);
		return (0);
	}
	
	return (1);
}

int	lex_L(t_lex *lex, char *line, int i)
{
	(void)lex;
	(void)line;
	(void)i;
	return (1);
}

int	lex_objects(t_lex *lex, char *line, int i)
{
	(void)lex;
	(void)line;
	(void)i;
	return (1);
}*/
