/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 13:44:50 by nrandria          #+#    #+#             */
/*   Updated: 2016/05/07 17:21:29 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_hook_m(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "mandelbrot");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? key_redraw_mandelbrot(e) : 0;
	(key == MINUS) ? e->zoom /= 1.1 : 0;
	(key == MINUS) ? key_redraw_mandelbrot(e) : 0;
	(key == I) ? e->iter_max += 20 : 0;
	(key == I) ? key_redraw_mandelbrot(e) : 0;
	if (key == J)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == J) ? key_redraw_mandelbrot(e) : 0;
	(key == R) ? init_mandelbrot(e) : 0;
	(key == R) ? key_redraw_mandelbrot(e) : 0;
	key_color(key, e, "mandelbrot");
	return (1);
}

int			key_hook_j(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "julia");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? key_redraw_julia(e) : 0;
	(key == MINUS) ? e->zoom /= 1.1 : 0;
	(key == MINUS) ? key_redraw_julia(e) : 0;
	(key == I) ? e->iter_max += 20 : 0;
	(key == I) ? key_redraw_julia(e) : 0;
	if (key == J)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == J) ? key_redraw_julia(e) : 0;
	(key == R) ? init_julia(e) : 0;
	(key == R) ? key_redraw_julia(e) : 0;
	(key == 49) ? e->motion++ : 0;
	key_color(key, e, "julia");
	return (1);
}

int			key_hook_t(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "tricorn");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? key_redraw_tricorn(e) : 0;
	(key == MINUS) ? e->zoom /= 1.1 : 0;
	(key == MINUS) ? key_redraw_tricorn(e) : 0;
	(key == I) ? e->iter_max += 20 : 0;
	(key == I) ? key_redraw_tricorn(e) : 0;
	if (key == J)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == J) ? key_redraw_tricorn(e) : 0;
	(key == R) ? init_tricorn(e) : 0;
	(key == R) ? key_redraw_tricorn(e) : 0;
	key_color(key, e, "tricorn");
	return (1);
}

int			key_hook_b(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "burn");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? key_redraw_burning_ship(e) : 0;
	(key == MINUS) ? e->zoom /= 1.1 : 0;
	(key == MINUS) ? key_redraw_burning_ship(e) : 0;
	(key == I) ? e->iter_max += 20 : 0;
	(key == I) ? key_redraw_burning_ship(e) : 0;
	if (key == J)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == J) ? key_redraw_burning_ship(e) : 0;
	(key == R) ? init_burning_ship(e) : 0;
	(key == R) ? key_redraw_burning_ship(e) : 0;
	key_color(key, e, "burn");
	return (1);
}

int			key_hook_c(int key, t_env *e)
{
	(key == ESC) ? key_quit(e) : 0;
	key_direction(key, e, "chameleon");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? key_redraw_chameleon(e) : 0;
	(key == MINUS) ? e->zoom /= 1.1 : 0;
	(key == MINUS) ? key_redraw_chameleon(e) : 0;
	(key == I) ? e->iter_max += 20 : 0;
	(key == I) ? key_redraw_chameleon(e) : 0;
	if (key == J)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == J) ? key_redraw_chameleon(e) : 0;
	(key == R) ? init_chameleon(e) : 0;
	(key == R) ? key_redraw_chameleon(e) : 0;
	key_color(key, e, "chameleon");
	return (1);
}
