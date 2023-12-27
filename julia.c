/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:06:12 by lperez-h          #+#    #+#             */
/*   Updated: 2023/12/27 13:04:15 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_numbers(int x, int y, t_fractal *fractal);

void	put_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			julia_numbers(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img, 0, 0);
}

void	julia_numbers(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	double		temp;
	int			i;

	z.real = x / RATIO * fractal->zoom + fractal->shift_x;
	z.complex = -y / RATIO * fractal->zoom + fractal->shift_y;
	i = 0;
	while (i++ < fractal->iterations_definition)
	{
		temp = z.real * z.real - z.complex * z.complex + fractal->julia_x;
		z.complex = 2 * z.real * z.real + fractal->julia_y;
		z.real = temp;
		if ((z.real * z.real + z.complex * z.complex) > fractal->iterations_definition)
		{
			my_pixel_put(x, y, fractal->img, fractal->color * (1 % 256));
			return ;
		}
	}
	my_pixel_put(x, y, fractal, BLUE);
}
