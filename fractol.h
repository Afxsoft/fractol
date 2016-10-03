/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 13:36:33 by aouloube          #+#    #+#             */
/*   Updated: 2016/10/03 13:43:54 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define HEIGTH 1280
# define WIDTH 1080
# define WHT 0xFFFFFF

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69
# define MINUS 78
# define I 34
# define J 38
# define R 15

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				iter_max;
	int				x;
	int				y;

	int				motion;

	int				r;
	int				g;
	int				b;

	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;

	double			image_x;
	double			image_y;

	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;

	double			i;
}					t_env;

void				error_parsing(void);

void				select_m(t_env *e, char *av);
void				select_j(t_env *e, char *av);
void				select_t(t_env *e, char *av);
void				select_b(t_env *e, char *av);
void				select_c(t_env *e, char *av);
void				select_s(t_env *e, char *av);

void				init_env(t_env *e, char *av);
void				init_mandelbrot(t_env *e);
void				init_julia(t_env *e);
void				init_tricorn(t_env *e);
void				init_burning_ship(t_env *e);
void				init_chameleon(t_env *e);
void				init_sword(t_env *e);

void				menu(t_env *e);

void				draw_mandelbrot(t_env *e);
void				draw_julia(t_env *e);
void				draw_tricorn(t_env *e);
void				draw_burning_ship(t_env *e);
void				draw_chameleon(t_env *e);
void				draw_sword(t_env *e);

void				set_pixel_color(t_env *e);

void				key_redraw_mandelbrot(t_env *e);
void				key_redraw_julia(t_env *e);
void				key_redraw_tricorn(t_env *e);
void				key_redraw_burning_ship(t_env *e);
void				key_redraw_chameleon(t_env *e);
void				key_redraw_sword(t_env *e);

void				key_quit(t_env *e);
void				key_color(int key, t_env *e, char *name);
void				key_direction(int key, t_env *e, char *name);

int					key_hook_m(int key, t_env *e);
int					key_hook_j(int key, t_env *e);
int					key_hook_t(int key, t_env *e);
int					key_hook_b(int key, t_env *e);
int					key_hook_c(int key, t_env *e);
int					key_hook_s(int key, t_env *e);

int					key_mouse_m(int key, int x, int y, t_env *e);
int					key_mouse_j(int key, int x, int y, t_env *e);
int					key_mouse_t(int key, int x, int y, t_env *e);
int					key_mouse_b(int key, int x, int y, t_env *e);
int					key_mouse_c(int key, int x, int y, t_env *e);
int					key_mouse_s(int key, int x, int y, t_env *e);

int					julia_motion(int x, int y, t_env *e);
double				rush(int key);

#endif
