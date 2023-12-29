/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:24:52 by lperez-h          #+#    #+#             */
/*   Updated: 2023/12/29 12:07:40 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_ESCAPE)
		close_handle(fractal);
	else if (keysym == XK_LEFT)
		fractal->shift_x += (0.25 * fractal->zoom);
	else if (keysym == XK_RIGHT)
		fractal->shift_x -= (0.25 * fractal->zoom);
	else if (keysym == XK_UP)
		fractal->shift_y -= (0.25 * fractal->zoom);
	else if (keysym == XK_DOWN)
		fractal->shift_y += (0.25 * fractal->zoom);
	else if (keysym == XK_PLUS)
		fractal->iterations_definition += 10;
	else if (keysym == XK_MINUS)
		fractal->iterations_definition -= 10;
	else if (keysym == CHANGE)
		fractal->color += 0xFFFFFF / 100;
	else if (keysym == BACK)
		fractal->color -= 0xFFFFFF / 100;
	else if (keysym == PSYCHO)
		fractal->color += MAGENTA_BURST;
	define_fractal(fractal, fractal->name);
	return (0);
}

int	julia_follow(int x, int y, t_fractal *fractal)
{
	if (fractal->left_click == 1 && ft_strncmp(fractal->name, "julia", 5) == 0)
	{
		fractal->julia_x = x / RATIO * fractal->zoom + fractal->shift_x;
		fractal->julia_y = -y / RATIO * fractal->zoom + fractal->shift_y;
		put_julia(fractal);
	}
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	double	x_before;
	double	y_before;
	double	x_after;
	double	y_after;

	x_before = x / RATIO * fractal->zoom + fractal->shift_x;
	y_before = -y / RATIO * fractal->zoom + fractal->shift_y;
	if (button == MOUSE_WHEEL_UP)
		fractal->zoom *= 0.98;
	else if (button == MOUSE_WHEEL_DOWN)
		fractal->zoom *= 1.1;
	else if (button == MOUSE_BTN)
		fractal->left_click = 1;
	else if (button == MOUSE_BTN_2)
		fractal->left_click = 0;
	else
		return (1);
	x_after = x / RATIO * fractal->zoom + fractal->shift_x;
	y_after = -y / RATIO * fractal->zoom + fractal->shift_y;
	fractal->shift_x += x_before - x_after;
	fractal->shift_y += y_before - y_after;
	define_fractal(fractal, fractal->name);
	return (0);
}

/*int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if(button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}*/