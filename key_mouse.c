/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 13:39:27 by aouloube          #+#    #+#             */
/*   Updated: 2016/10/03 13:39:30 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_mouse_j(int key, int x, int y, t_env *e)
{
	double x_real;
	double y_real;

	if (y > 0)
	{
		x_real = (x / e->zoom) + e->x1;
		y_real = (y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_julia(e);
		}
		if (key == 5)
		{
			e->zoom /= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_julia(e);
		}
	}
	return (0);
}

int			key_mouse_m(int key, int x, int y, t_env *e)
{
	double x_real;
	double y_real;

	if (y > 0)
	{
		x_real = (x / e->zoom) + e->x1;
		y_real = (y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_mandelbrot(e);
		}
		if (key == 5)
		{
			e->zoom /= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_mandelbrot(e);
		}
	}
	return (0);
}

int			key_mouse_t(int key, int x, int y, t_env *e)
{
	double x_real;
	double y_real;

	if (y > 0)
	{
		x_real = (x / e->zoom) + e->x1;
		y_real = (y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_tricorn(e);
		}
		if (key == 5)
		{
			e->zoom /= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_tricorn(e);
		}
	}
	return (0);
}

int			key_mouse_b(int key, int x, int y, t_env *e)
{
	double x_real;
	double y_real;

	if (y > 0)
	{
		x_real = (x / e->zoom) + e->x1;
		y_real = (y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_burning_ship(e);
		}
		if (key == 5)
		{
			e->zoom /= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_burning_ship(e);
		}
	}
	return (0);
}

int			key_mouse_c(int key, int x, int y, t_env *e)
{
	double x_real;
	double y_real;

	if (y > 0)
	{
		x_real = (x / e->zoom) + e->x1;
		y_real = (y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_chameleon(e);
		}
		if (key == 5)
		{
			e->zoom /= 1.1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
			key_redraw_chameleon(e);
		}
	}
	return (0);
}
