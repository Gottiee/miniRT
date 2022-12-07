/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:18:19 by eedy              #+#    #+#             */
/*   Updated: 2022/12/07 17:49:30 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	check_next(char c)
{
	if (!c)
		return (1);
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

void	set_type(t_lex *lex, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'A' && check_next(line[i + 1]))
		lex->type = A;
	else if (line[i] == 'C' && check_next(line[i + 1]))
		lex->type = C;
	else if (line[i] == 'L' && check_next(line[i + 1]))
		lex->type = L;
	else if (line[i] == 's' && line[i + 1] && line[i + 1] == 'p'
		&& check_next(line[i + 2]))
		lex->type = SP;
	else if (line[i] == 'p' && line[i + 1] && line[i + 1] == 'l'
		&& check_next(line[i + 2]))
		lex->type = PL;
	else if (line[i] == 'c' && line[i + 1] && line[i + 1] == 'y'
		&& check_next(line[i + 2]))
		lex->type = CY;
	else	
		lex->type = NONE;
}

int	lexeur(t_lex *lex, char *line, int i)
{
	int value;

	while (*line && (*line == ' ' || *line == '\t'))		
		line ++;	
	if (!*line)	
		return (0);
	set_type(lex, line);
	if (lex->type == NONE)
	{
		printf("Error\nWrong type line %d\n", i);
		return (0);
	}
	line = string_move(line);
	if (!*line)
	{
		printf("Error\nLine %d isn't complet\n", i);
		return (0);
	}
	if (lex->type == A)
		value = lex_A(lex, line, i);
	if (lex->type == C)
		value = lex_C(lex, line, i);
	if (lex->type == L)
		value = lex_L(lex, line, i);
	if (lex->type == CY || lex->type == SP || lex->type == PL)
		value = lex_objects(lex, line, i);
	if (value == 0)
		return (0);
	return (1);
}

int	verif_verif(int *verif)
{
	if (verif[C] > 1 || verif[L] > 1 || verif[A] > 1)
		return (printf("Error\nToo many cams and/or lights and/or ambiant lights\n"), 0);
	if (verif[C] == 0 || verif[L] == 0 || verif[A] == 0)
		return (printf("Error\nNo cam and/or light and/or ambiant light\n"), 0);
	return (1);
}

int	object(int fd)
{
	t_lex	lex;
	char	*line;
	int		nbr_line;
	int		verif[8];

	ft_bzero(verif, sizeof(int) * 8);
	nbr_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		nbr_line ++;
		if (line[0] == '\n')
		{
			line = get_next_line(fd);
			continue ;
		}
		if (!verify_line(line, nbr_line))
			return (0);
		if (lexeur(&lex, line, nbr_line))
		{
			if (!parser(lex, verif))
				return (printf("Error\nLine %d: Invalid range\n",
				nbr_line), 0);
			new_object(lex);
		}
		else
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	return (verif_verif(verif));
}
