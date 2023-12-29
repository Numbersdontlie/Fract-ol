/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:36:39 by lperez-h          #+#    #+#             */
/*   Updated: 2023/12/29 14:24:28 by lperez-h         ###   ########.fr       */
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

	z.x = 0.0;
	z.y = 0.0;
	c.x = x / RATIO * fractal->zoom + fractal->shift_x;
	c.y = -y / RATIO * fractal->zoom + fractal->shift_y;
	i = 0;
	while (i++ < fractal->iterations_definition)
	{
		temp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
		if (z.x * z.x + z.y * z.y > fractal->escape_value)
		{
			my_pixel_put(x, y, fractal, fractal->color * (i % 256));
			return ;
		}
	}
	my_pixel_put(x, y, fractal, MAGENTA_BURST);
}
