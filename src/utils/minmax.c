/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:22:10 by gmansuy           #+#    #+#             */
/*   Updated: 2022/12/02 18:24:11 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

double	ft_min(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}

double	ft_max(double a, double b)
{
	if (a >= b)
		return (a);
	return (b);
}