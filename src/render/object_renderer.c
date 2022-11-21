/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:44 by eedy              #+#    #+#             */
/*   Updated: 2022/11/21 16:26:16 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	init_pointer(int (*hit[2])(t_record *rec, t_ray r, t_vec2 limit, t_point light))
{
	hit[SP] = &hit_sphere;
	hit[L] = &hit_light;
}

int	hit_global(t_ray r, t_record *rec, t_point light)
{
	t_hit_lst	*list;
	t_record	rec_tmp;
	t_vec2		limit;
	int			hit_any;
	int 		(*hit[8])(t_record *rec, t_ray r, t_vec2 limit, t_point light);
	
	init_pointer(hit);
	limit.x = 0;
	limit.y = DBL_MAX;
	hit_any = 0;
	list = get_hit(NULL, 0);
	while (list)
	{
		rec_tmp.closest = list->object;
		rec_tmp.type = 0;
		//poiteur sur fonction pour modifier et ne pas aller hit sphere tout le tempps?
		if (hit[list->type](&rec_tmp, r, limit, light))
		{
			hit_any = 1;
			limit.y = rec_tmp.t;
			*rec = rec_tmp;
			rec->obj_id = list->id;
		}
		list = list->next;
	}
	if (!hit_any)
		return (0);
	if (rec->type == SP)
		shadow_render(rec, light);
	return (1);
}

//Peut etre un debut d'antialiasing, a tester
// if (discr < 0.001)
// 	rec->light_level *= 0.5;
