/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:20:27 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/28 00:28:41 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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