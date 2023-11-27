/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:52:06 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/27 16:14:19 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
		|| argc == 4 && ft_strncmp(argv[1], "julia", 5))
	{
		//Input is correct and I can launch the app
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}