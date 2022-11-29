/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:30:14 by gmansuy           #+#    #+#             */
/*   Updated: 2022/11/29 17:12:08 by gmansuy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../header/minirt.h"

// t_point        ft_multdir(t_point p, t_matrix m)
// {
//     t_point res;

//     res.x = p.x * m.d[0][0] + p.y * m.d[1][0] + p.z * m.d[2][0];
//     res.y = p.x * m.d[0][1] + p.y * m.d[1][1] + p.z * m.d[2][1];
//     res.z = p.x * m.d[0][2] + p.y * m.d[1][2] + p.z * m.d[2][2];
//     return (res);
// }

// t_matrix    ft_look_at(t_point origin, t_point rotation)
// {
//     t_matrix    m;
//     t_point        random;
//     t_point        right;
//     t_point        up;

//     random = unit_vector((t_point){0, 1, 0});
//     right = unit_vector(cross(random, rotation));
//     up = unit_vector(cross(rotation, right));
//     m.d[0][0] = right.x;
//     m.d[0][1] = right.y;
//     m.d[0][2] = right.z;
//     m.d[1][0] = up.x;
//     m.d[1][1] = up.y;
//     m.d[1][2] = up.z;
//     m.d[2][0] = rotation.x;
//     m.d[2][1] = rotation.y;
//     m.d[2][2] = rotation.z;
//     m.d[3][0] = origin.x;
//     m.d[3][1] = origin.y;
//     m.d[3][2] = origin.z;
//     return (m);
// }

// // t_point        ft_canvas_to_viewport(double x, double y, t_cam *cam)
// // {
// //     t_point    ret;
	
// //     ret.x = x * fovk / g_width;
// //     ret.y = y * fovk / (g_width / g_height) / g_height;
// //     ret.z = 1;
// //     return (ret);
// // }


// t_vec3        rotate_ray(t_ray r, t_cam cam)
// {
//     t_matrix	m;

//     m = ft_look_at(cam.origin, unit_vector(cam.rotate));
//     // ret.origin = ft_multdir((t_point){0, 0, 0}, m);
//     // ret.direction = ft_canvas_to_viewport(x, y, cam);
//     r.dir = ft_multdir(r.dir, m);
//     // r.dir = unit_vector(minus(r.dir, r.orig));
//     return (r.dir);
// }