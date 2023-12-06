/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:12:33 by lperez-h          #+#    #+#             */
/*   Updated: 2023/12/06 14:17:34 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

//[0..799]->[-2..+2]
double	map(double num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.complex = z1.complex + z2.complex;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.complex * z.complex);
	result.complex = 2 * z.real * z.complex;
	return (result);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	unsigned char *p1;
	unsigned char *p2;

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
	long	integer_part;
	double	fraction_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fraction_part = 0;
	sign = +1;
	pow = 1;
	while ((*s > 9 && *s <= 13) || *s == 32)
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
	return ((integer_part + fraction_part) * sign);
}
