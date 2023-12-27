/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:12:33 by lperez-h          #+#    #+#             */
/*   Updated: 2023/12/27 13:11:06 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//[0..799]->[-2..+2]
double	map(double num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while ((n != '\0') && (*p1 != '\0') && (*p1 == *p2))
	{
		p1++;
		p2++;
		n--;
	}
	if (n != '\0')
		return (*p1 - *p2);
	else
		return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while(*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

double	atodbl(char *s)
{
	double	integer_part;
	double	fraction_part;
	int		sign;
	int		pow;
	
	integer_part = 0;
	fraction_part = 0;
	sign = 1;
	pow = 1;
	if (*s == '+' || *s == '-')
	{
		if(*s == '-')
			sign = -1;
		s++;
	}
	while (*s != '.' && *s)
		integer_part = (integer_part * 10.0) + (*s++ - '0');
	if (*s == '.')
		s++;
	while(*s)
	{
		pow /= 10;
		fraction_part = fraction_part + (*s++ - '0') * pow;
	}
	return (sign * (integer_part + fraction_part));
}
	/*while ((*s > 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if(*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		pow /= 10;
		fraction_part = fraction_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fraction_part) * sign);*/

void	define_fractal(t_fractal *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 7) == 0)
		put_mandelbrot(fractal);
	else if (ft_strncmp(name, "julia", 5) == 0)
		put_julia(fractal);
	//else if (ft_strncmp(name, "ship", 4) == 0)
	//	put_ship(fractal); //ToDo
}

void	my_pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int	offset;

	offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
	*(unsigned int *)(fractal->pixels_ptr + offset) = color;
}
