/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:38 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/14 15:42:35 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minirt.h"

int main(int argc, char const *argv[])
{
	t_vec	u;
	t_vec	v;
	t_vec	*p;
	
	(void)argc;
	(void)argv;
	init_vec(&u, 2, 0, 3);
	init_vec(&v, 4, 4, 4);
	p = div_const(&u, 3.0);
	
	printv(p);
	return (0);
}
