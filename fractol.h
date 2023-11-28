/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:05:55 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/28 16:05:31 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

#define ERROR_MESSAGE "Please enrer \n\t"./fractol maldelbrot\" or \n\t./fractol julia <value 1> <value 2>""
#define WIDTH 800
#define HEIGHT 800

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define MAGENTA_BURST 0xFF00FF
#define LIME_SHOCK 0xCCFF00
#define NEON_ORANGE 0xFF6600
#define PSYCHEDELIC_PURPLE 0x660866
#define AQUA_DREAM 0x33CCCC
#define HOT_PINK 0xFF66B2
#define ELECTRIC_BLUE 0x0066FF
#define LAVA_RED 0xFF3300

typedef struct s_complex
{
	double	real;
	double	complex;
}	t_complex;

typedef struct s_image
{
	void	*image_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp; //bits per pixels
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection; //mlx_init()
	void	*mlx_window; //mlx_new_window()
	t_image	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
}	t_fractal;


int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		fractal_init(t_fractal *fractal);
double		map(double num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		fractal_render(t_fractal *fractal);
int			key_handle(int keysym, t_fractal *fractal);
int			close_handle(t_fractal *fractal);





#endif