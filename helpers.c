/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 00:47:45 by fguzman           #+#    #+#             */
/*   Updated: 2019/11/28 03:10:46 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int	a_value(int point)
{
	int				abs;
	unsigned int	pos;

	pos = point;
	abs = -1;
	if (point <= 0)
		pos = abs * point;
	return (pos);
}

void			set_fractalb(t_fractal *fractal)
{
	fractal->i = 0;
	fractal->zoom = 0.5;
	fractal->max = 30;
	fractal->movex = 0;
	fractal->movey = 0;
}

void			set_fractalj(t_fractal *fractal)
{
	fractal->i = 0;
	fractal->zoom = 1;
	fractal->max = 30;
	fractal->movex = 0;
	fractal->movey = 0;
}

void			set_fractalm(t_fractal *fractal)
{
	fractal->i = 0;
	fractal->zoom = 1;
	fractal->max = 30;
	fractal->movex = -0.5;
	fractal->movey = 0;
}

int				juliamouse(int x, int y, t_mlx *mlx)
{
	if (mlx->f == 2)
	{
		if (x >= 0 && x <= WIN_WIDTH && y <= WIN_HEIGHT && y >= 0)
		{
			mlx->fractal.movex += (double)(x - WIN_WIDTH / 2) * 0.00009;
			mlx->fractal.movey += (double)(y - WIN_HEIGHT / 2) * 0.00009;
			draw(mlx, mlx->f);
		}
	}
	return (0);
}
