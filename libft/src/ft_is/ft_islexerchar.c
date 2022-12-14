/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islexerchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:59:25 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/25 18:59:27 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(int c)
{
	return (c == ' ' || c == '\t');
}

int	is_quote(int c)
{
	if (c == 39)
		return (1);
	if (c == 34)
		return (2);
	return (0);
}

int	is_arrow(char c)
{
	if (c == '<')
		return (1);
	if (c == '>')
		return (2);
	return (0);
}

int	is_pipe(int c)
{
	return (c == '|');
}

int	is_special(int c)
{
	return (is_pipe(c) || is_arrow(c));
}
