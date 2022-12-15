/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:21:44 by eedy              #+#    #+#             */
/*   Updated: 2022/12/15 12:37:29 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	call_type(t_lex *lex, char *line, int i, int *value)
{
	if (lex->type == A)
		*value = lex_a(lex, line, i);
	if (lex->type == C)
		*value = lex_C(lex, line, i);
	if (lex->type == L)
		*value = lex_l(lex, line, i);
	if (lex->type == CY || lex->type == SP || lex->type == PL)
		*value = lex_objects(lex, line, i);
}

int	do_parser(t_lex lex, int *verif, int nbr_line)
{
	if (!parser(lex, verif))
	{
		return (printf("Error\nLine %d: Invalid range\n",
				nbr_line), 0);
	}
	new_object(lex);
	return (1);
}
