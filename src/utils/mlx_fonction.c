/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fonction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmansuy <gmansuy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:54:07 by eedy              #+#    #+#             */
/*   Updated: 2022/12/15 11:47:07 by eedy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	handle_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->i.i);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	magic_free();
	exit(0);
}

void	keypress_manage(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_image(data->mlx_ptr, data->i.i);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		magic_free();
		exit(0);
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	keypress_manage(keysym, data);
	move(keysym, data);
	return (0);
}

int	launch_render(t_data *data)
{
	if (data->render_image)
	{
		render(data);
		data->render_image = 0;
	}
	return (0);
}

int	mlx_center(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (magic_free(), exit(0), 0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W, WINDOW_H, "MiniRT");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (magic_free(), exit(0), 0);
	}
	data->i.i = mlx_new_image(data->mlx_ptr, WINDOW_W, WINDOW_H);
	if (!data->i.i)
		return (magic_free(), exit(0), 0);
	data->i.a = mlx_get_data_addr(data->i.i,
			&data->i.b, &data->i.l, &data->i.e);
	if (!data->i.a)
		return (magic_free(), exit(0), 0);
	init_move(data);
	mlx_loop_hook(data->mlx_ptr, &launch_render, data);
	mlx_hook(data->win_ptr, 17, StructureNotifyMask, &handle_destroy, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->i.i);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (1);
}
