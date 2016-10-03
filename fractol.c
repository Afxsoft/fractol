/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 13:36:18 by aouloube          #+#    #+#             */
/*   Updated: 2016/10/03 13:36:20 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				error_parsing(void)
{
	write(2, "usage : ./fractol mandelbrot\n", 30);
	write(2, "        ./fractol julia\n", 25);
	write(2, "        ./fractol tricorn\n", 27);
	write(2, "        ./fractol burn\n", 24);
	write(2, "        ./fractol chameleon\n", 28);
	write(2, "        ./fractol sword\n", 25);
	write(2, "        ./fractol all\n", 23);
	exit(-1);
}

void				set_pixel_color(t_env *e)
{
	if (e->i == e->iter_max)
	{
		e->data[(e->size_line * e->y) + (4 * e->x) + 2] = 0;
		e->data[(e->size_line * e->y) + (4 * e->x) + 1] = 0;
		e->data[(e->size_line * e->y) + (4 * e->x)] = 0;
	}
	else
	{
		e->data[(e->size_line * e->y) + (4 * e->x) + 2] =
			(e->i * 255 / e->iter_max) * e->b;
		e->data[(e->size_line * e->y) + (4 * e->x) + 1] =
			(e->i * 255 / e->iter_max) * e->b * e->g;
		e->data[(e->size_line * e->y) + (4 * e->x)] =
			(e->i * 255 / e->iter_max) * e->r * e->r * e->r;
	}
}

void				menu(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 0, WHT, "ZOOM +/-");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 15, WHT,
			"ARROW up/down/left/right");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 30, WHT, "RUSH 1/2/3");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 45, WHT, "COLOR 4/5/6");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 60, WHT, "ITER I/J");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 75, WHT, "RESET R");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 90, WHT, "QUIT ESC");
}

void				init_env(t_env *e, char *av)
{
	e->mlx_ptr = mlx_init();
	e->img_ptr = mlx_new_image(e->mlx_ptr, HEIGTH, WIDTH);
	e->win_ptr = mlx_new_window(e->mlx_ptr, HEIGTH, WIDTH, "Fract_ol");
	e->data =
		mlx_get_data_addr(e->img_ptr, &(e->bpp), &(e->size_line), &(e->endian));
	if (!(ft_strcmp("mandelbrot", av)))
		init_mandelbrot(e);
	else if (!(ft_strcmp("julia", av)))
		init_julia(e);
	else if (!(ft_strcmp("tricorn", av)))
		init_tricorn(e);
	else if (!(ft_strcmp("burn", av)))
		init_burning_ship(e);
	else if (!(ft_strcmp("chameleon", av)))
		init_chameleon(e);
	else if (!(ft_strcmp("sword", av)))
		init_sword(e);
}

int					main(int ac, char **av)
{
	t_env			e;

	if (ac == 2)
	{
		(!(ft_strcmp("mandelbrot", av[1]))) ?
			select_m(&e, av[1]) : 0;
		(!(ft_strcmp("julia", av[1]))) ?
			select_j(&e, av[1]) : 0;
		(!(ft_strcmp("tricorn", av[1]))) ?
			select_t(&e, av[1]) : 0;
		(!(ft_strcmp("burn", av[1]))) ?
			select_b(&e, av[1]) : 0;
		(!(ft_strcmp("chameleon", av[1]))) ?
			select_c(&e, av[1]) : 0;
		(!(ft_strcmp("sword", av[1]))) ?
			select_s(&e, av[1]) : 0;
		(!(ft_strcmp("all", av[1]))) ?
			system("sh all_fractols.sh") : error_parsing();
	}
	else
		error_parsing();
	return (0);
}
