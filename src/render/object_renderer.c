/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/11/18 15:56:22 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	hit_global(t_ray r, t_record *rec, double min, double max)
{
	t_hit_lst	*list;
	t_record	rec_tmp;
	t_vec2		limit;
	int			hit_any;	
	
	limit.x = min;
	limit.y = max;
	hit_any = 0;
	list = get_hit(NULL);
	while (list)
	{
		//poiteur sur fonction pour modifier et ne pas aller hit sphere tout le tempps?
		if (hit_sphere(&rec_tmp, r, list->object, limit))
		{
			hit_any = 1;
			limit.y = rec_tmp.t;
			*rec = rec_tmp;
		}
		list = list->next;
	}
	return (hit_any);
}
