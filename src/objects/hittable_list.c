/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:49:08 by eedy              #+#    #+#             */
/*   Updated: 2022/11/16 18:13:58 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_hit_lst	*new_hit(void *obj)
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
	return (new);	
}

void	add_hit(void *obj, t_hit_lst **list)
{
	t_hit_lst	*p;
	t_hit_lst	*new;

	p = *list;
	new = new_hit(obj);
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

t_hit_lst	*get_hit(void *obj)
{
	static t_hit_lst	*m_stack = NULL;
	if (obj)
	{
		if (!m_stack)
			m_stack = new_hit(obj);
		else
			add_hit(obj, &m_stack);
	}
	return (m_stack);
}
