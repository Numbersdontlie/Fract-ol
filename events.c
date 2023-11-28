/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:24:52 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/28 16:35:50 by lperez-h         ###   ########.fr       */
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
	else if (keysym == XK_Left);
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right);
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up);
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down);
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus);
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus);
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
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
}