/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:27:25 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/21 15:44:23 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	animation(t_data *data)
{
	static int	i = 0;

	if (i < 17)
		move(XK_u, data);
	else if (i < 34)
		move(XK_j, data);
	else if (i < 51)
		move(XK_o, data);
	else if (i < 68)
		move(XK_l, data);
	else
		i = 0;
	i ++;
}