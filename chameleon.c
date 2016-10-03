/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chameleon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 12:54:12 by aouloube          #+#    #+#             */
/*   Updated: 2016/10/03 12:54:14 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			select_c(t_env *e, char *av)
{
	init_env(e, av);
	draw_chameleon(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	menu(e);
	mlx_mouse_hook(e->win_ptr, key_mouse_c, e);
	mlx_hook(e->win_ptr, 2, 3, key_hook_c, e);
	mlx_loop(e->mlx_ptr);
}

void			init_chameleon(t_env *e)
{
	e->x1 = -2;
	e->x2 = 2.5;
	e->y1 = -1.5;
	e->y2 = 3;
	e->c_r = 0.285;
	e->c_i = 0.01;
	e->zoom = 345.23;
	e->iter_max = 140;
	e->r = 5;
	e->g = 5;
	e->b = 5;
	e->motion = 0;
}

void			draw_chameleon(t_env *e)
{
	e->image_x = HEIGTH;
	e->image_y = WIDTH;
	e->x = 0;
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = -2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			set_pixel_color(e);
			e->y++;
		}
		e->x++;
	}
}

void			key_redraw_chameleon(t_env *e)
{
	draw_chameleon(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	menu(e);
}
