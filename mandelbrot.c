/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:36:39 by lperez-h          #+#    #+#             */
/*   Updated: 2023/12/27 13:14:13 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandel_numbers(int x, int y, t_fractal *fractal);

void	put_mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mandel_numbers(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img, 0, 0);
}

static void	mandel_numbers(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			i;

	z.real = 0.0;
	z.complex = 0.0;
	c.real = x / RATIO * fractal->zoom + fractal->shift_x;
	c.complex = -y / RATIO * fractal->zoom + fractal->shift_y;
	i = 0;
	while (i++ < fractal->iterations_definition)
	{
		temp = z.real * z.real - z.complex * z.complex + c.real;
		z.complex = 2 * z.real * z.complex + c.complex;
		z.real = temp;
		if (z.real * z.real + z.complex * z.complex > fractal->escape_value)
		{
			my_pixel_put(x, y, fractal, fractal->color * (1 % 256));
			return ;
		}
	}
	my_pixel_put(x, y, fractal, MAGENTA_BURST);
}
