/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:59:21 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/28 16:08:01 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

static void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_len) + (x * (image->bpp / 8));
	*(unsigned int *)(image->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	//1st iteration
	z.real = 0.0;
	z.complex = 0.0;
	//pixel coordinate x(real) && y(complex) and scaled to fit mandel needs
	c.real = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.complex = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	//how many times iterate z^2 + c to check if point scaped
	while(i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if((z.real * z.real) + (z.complex * z.complex) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
 		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img, 0, 0);
}