/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:28:27 by meudier           #+#    #+#             */
/*   Updated: 2022/12/08 14:39:33 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

t_matrix	get_transfo_matrix(t_vec3 cam_orig, t_vec3 cam_dir)
{
	t_matrix	matrix;
	t_vec3		temp;

	temp.x = 0;
	temp.y = 1;
	temp.z = 0;
	eq_vector(&matrix.forward, mult(normalize(cam_dir), -1));
	if ((matrix.forward.x == 0 && matrix.forward.y == 1
			&& matrix.forward.z == 0)
		|| ((matrix.forward.x == 0 && matrix.forward.y == -1
				&& matrix.forward.z == 0)))
	{
		matrix.right.x = 1;
		matrix.right.y = 0;
		matrix.right.z = 0;
	}
	else
		eq_vector(&matrix.right, cross(temp, matrix.forward));
	eq_vector(&matrix.up, cross(matrix.right, matrix.forward));
	eq_vector(&matrix.cam, cam_orig);
	return (matrix);
}

t_vec3	vector_x_matrix(t_vec3 v, t_matrix m, int i)
{
	t_vec3	rslt;

	rslt.x = v.x * m.right.x + v.y * m.up.x + v.z * m.forward.x + i * m.cam.x;
	rslt.y = v.x * m.right.y + v.y * m.up.y + v.z * m.forward.y + i * m.cam.y ;
	rslt.z = v.x * m.right.z + v.y * m.up.z + v.z * m.forward.z + i * m.cam.z;
	return (rslt);
}

void	eq_matrix(t_matrix *m1, t_matrix m2)
{
	eq_vector(&m1->right, m2.right);
	eq_vector(&m1->up, m2.up);
	eq_vector(&m1->forward, m2.forward);
	eq_vector(&m1->cam, m2.cam);
}
