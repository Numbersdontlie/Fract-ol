/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:05:55 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/27 16:04:20 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enrer \n\t"./fractol maldelbrot\" or \n\t./fractol julia <value 1> <value 2>""

typedef struct s_image
{
	void	*image_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp; //bits per pixels
	int		endian;
	int		line_len;
};	t_image

typedef struct s_fractal
{
	void	*mlx_connection; //mlx_init()
	void	*mlx_window; //mlx_new_window()
	t_image	img;
	//Hooks member variables //ToDo
};	t_fractal;


int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);





#endif