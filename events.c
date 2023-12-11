/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:24:52 by lperez-h          #+#    #+#             */
/*   Updated: 2023/12/11 14:24:01 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.3 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.3 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.3 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.3 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	julia_follow(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, -2, +2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
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
	//else if (button == MOUSE_BTN)
	//	fractal->
	else
		return (1);
	x_after = x / RATIO * fractal->zoom + fractal->shift_x;
	y_after = -y / RATIO * fractal->zoom + fractal->shift_y;
	fractal->shift_x += x_before - x_after;
	fractal->shift_y += y_before - y_after;
	fractal_render(fractal);
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