/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 12:53:41 by aouloube          #+#    #+#             */
/*   Updated: 2016/10/03 12:53:49 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				select_b(t_env *e, char *av)
{
	init_env(e, av);
	draw_burning_ship(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	menu(e);
	mlx_mouse_hook(e->win_ptr, key_mouse_b, e);
	mlx_hook(e->win_ptr, 2, 3, key_hook_b, e);
	mlx_loop(e->mlx_ptr);
}

void				init_burning_ship(t_env *e)
{
	e->x1 = -3;
	e->x2 = 2.5;
	e->y1 = -2;
	e->y2 = 3;
	e->zoom = 259.37;
	e->iter_max = 80;
	e->r = 5;
	e->g = 5;
	e->b = 5;
	e->motion = 0;
}

void				draw_burning_ship(t_env *e)
{
	e->image_x = HEIGTH;
	e->image_y = WIDTH;
	e->x = 0;
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
				e->z_i = fabs(2 * e->z_i * e->tmp + e->c_i);
				e->i++;
			}
			set_pixel_color(e);
			e->y++;
		}
		e->x++;
	}
}

void				key_redraw_burning_ship(t_env *e)
{
	draw_burning_ship(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
	menu(e);
}
