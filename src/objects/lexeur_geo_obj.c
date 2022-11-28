/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur_geo_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:22:40 by eedy              #+#    #+#             */
/*   Updated: 2022/11/28 11:12:34 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int lex_SP(t_lex *lex, char *line, int i)
{
	if (!get_vector(&line, i, &lex->coord))
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	lex->radius = get_decimal(&line, i);
	if (!*line)
		return (isnt_complet(i, 0));
	if (!get_vector(&line, i, &lex->color))
		return (0);
	if (*line)
		return (isnt_complet(i, 1));
	return (1);
}

int	lex_PL(t_lex *lex, char *line, int i)
{
	if (!get_vector(&line, i, &lex->coord))
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	if (!get_vector(&line, i, &lex->orient))
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	if (!get_vector(&line, i, &lex->color))
		return (0);
	if (*line)
		return (isnt_complet(i, 1));
	return (1);
}

int	lex_CY(t_lex *lex, char *line, int i)
{
	if (!get_vector(&line, i, &lex->coord))
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	if (!get_vector(&line, i, &lex->orient))
		return (0);
	if (!*line)
		return (isnt_complet(i, 0));
	lex->radius = get_decimal(&line, i);
	if (!*line)
		return (isnt_complet(i, 0));
	lex->height = get_decimal(&line, i);
	if (!*line)
		return (isnt_complet(i, 0));
	if (!get_vector(&line, i, &lex->color))
		return (0);
	if (*line)
		return (isnt_complet(i, 1));
	return (1);
}
