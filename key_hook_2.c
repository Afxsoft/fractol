/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 13:39:06 by aouloube          #+#    #+#             */
/*   Updated: 2016/10/03 13:39:08 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			key_quit(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	exit(2);
}

double			rush(int key)
{
	static double rush = 0.3;

	if (key == 82)
		rush = 0.3;
	if (key == 83)
		rush = 0.001;
	if (key == 84)
		rush = 0.000001;
	return (rush);
}

void			key_color(int key, t_env *e, char *name)
{
	(key == 23) ? e->g += 2 : 0;
	(key == 22) ? e->b += 2 : 0;
	(key == 21) ? e->r += 2 : 0;
	if (!(ft_strcmp("mandelbrot", name)))
		key_redraw_mandelbrot(e);
	if (!(ft_strcmp("julia", name)))
		key_redraw_julia(e);
	if (!(ft_strcmp("tricorn", name)))
		key_redraw_tricorn(e);
	if (!(ft_strcmp("burn", name)))
		key_redraw_burning_ship(e);
	if (!(ft_strcmp("chameleon", name)))
		key_redraw_chameleon(e);
	if (!(ft_strcmp("sword", name)))
		key_redraw_sword(e);
}

void			key_direction(int key, t_env *e, char *name)
{
	double speed;

	speed = rush(key);
	(key == UP) ? e->y1 += speed : 0;
	(key == DOWN) ? e->y1 -= speed : 0;
	(key == LEFT) ? e->x1 += speed : 0;
	(key == RIGHT) ? e->x1 -= speed : 0;
	if (!(ft_strcmp("mandelbrot", name)))
		key_redraw_mandelbrot(e);
	if (!(ft_strcmp("julia", name)))
		key_redraw_julia(e);
	if (!(ft_strcmp("tricorn", name)))
		key_redraw_tricorn(e);
	if (!(ft_strcmp("burn", name)))
		key_redraw_burning_ship(e);
	if (!(ft_strcmp("chameleon", name)))
		key_redraw_chameleon(e);
	if (!(ft_strcmp("sword", name)))
		key_redraw_sword(e);
}

int				key_hook_s(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "sword");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? key_redraw_sword(e) : 0;
	(key == MINUS) ? e->zoom /= 1.1 : 0;
	(key == MINUS) ? key_redraw_sword(e) : 0;
	(key == I) ? e->iter_max += 20 : 0;
	(key == I) ? key_redraw_sword(e) : 0;
	if (key == J)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == J) ? key_redraw_sword(e) : 0;
	(key == R) ? init_sword(e) : 0;
	(key == R) ? key_redraw_sword(e) : 0;
	key_color(key, e, "sword");
	return (1);
}
