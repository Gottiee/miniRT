/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:08 by eedy              #+#    #+#             */
/*   Updated: 2022/11/21 13:18:39 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_hit_lst	*new_hit(void *obj, int type)
{
	t_hit_lst	*new;

	new = magic_malloc(sizeof(t_hit_lst) * 1);
	if (!new)
	{
		magic_free();
		exit(1);
	}
	new->next = NULL;
	new->object = obj;
	new->id = 0;
	new->type = type;
	return (new);	
}

void	add_hit(void *obj, t_hit_lst **list, int type)
{
	t_hit_lst	*p;
	t_hit_lst	*new;

	p = *list;
	new = new_hit(obj, type);
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->id = p->id + 1;
}

t_hit_lst	*get_hit(void *obj, int type)
{
	static t_hit_lst	*m_stack = NULL;
	if (obj)
	{
		if (!m_stack)
			m_stack = new_hit(obj, type);
		else
			add_hit(obj, &m_stack, type);
	}
	return (m_stack);
}
