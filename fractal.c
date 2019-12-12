/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:19:49 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/03 14:46:13 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		mandelbrot(t_fractal fractal, int x, int y)
{
	int i;

	fractal.pr = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * fractal.zoom * WIN_WIDTH)
		+ fractal.movex;
	fractal.pi = (y - WIN_HEIGHT / 2) /
		(0.5 * fractal.zoom * WIN_HEIGHT) + fractal.movey;
	fractal.oldim = 0;
	fractal.oldre = fractal.oldim;
	fractal.newim = fractal.oldre;
	fractal.newre = fractal.newim;
	i = 0;
	while (i < fractal.max)
	{
		fractal.oldre = fractal.newre;
		fractal.oldim = fractal.newim;
		fractal.newre = fractal.oldre * fractal.oldre -
			fractal.oldim * fractal.oldim + fractal.pr;
		fractal.newim = 2 * fractal.oldre * fractal.oldim + fractal.pi;
		if ((fractal.newre * fractal.newre + fractal.newim * fractal.newim) > 4)
			break ;
		i++;
	}
	return (i);
}

int		julia(t_fractal fractal, int x, int y)
{
	double	cre;
	double	cim;
	int		i;

	i = 0;
	cre = fractal.movex + -0.7;
	cim = fractal.movey + 0.27015;
	fractal.newre = 1.5 * (x - WIN_WIDTH / 2) /
		(0.5 * fractal.zoom * WIN_WIDTH) + fractal.movex;
	fractal.newim = (y - WIN_HEIGHT / 2) /
		(0.5 * fractal.zoom * WIN_HEIGHT) + fractal.movey;
	while (i < fractal.max)
	{
		fractal.oldre = fractal.newre;
		fractal.oldim = fractal.newim;
		fractal.newre = fractal.oldre * fractal.oldre -
			fractal.oldim * fractal.oldim + cre;
		fractal.newim = 2 * fractal.oldre * fractal.oldim + cim;
		if ((fractal.newre * fractal.newre + fractal.newim * fractal.newim) > 4)
			break ;
		i++;
	}
	return (i);
}

int		tricorn(t_fractal fractal, int x, int y)
{
	int i;

	fractal.pr = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * fractal.zoom * WIN_WIDTH)
		+ fractal.movex;
	fractal.pi = (y - WIN_HEIGHT / 2) /
		(0.5 * fractal.zoom * WIN_HEIGHT) + fractal.movey;
	fractal.oldim = 0;
	fractal.oldre = fractal.oldim;
	fractal.newim = fractal.oldre;
	fractal.newre = fractal.newim;
	i = 0;
	while (i < fractal.max)
	{
		fractal.oldre = fractal.newre;
		fractal.oldim = fractal.newim;
		fractal.newre = fractal.oldre * fractal.oldre -
			fractal.oldim * fractal.oldim + fractal.pr;
		fractal.newim = -2 * fractal.oldre * fractal.oldim + fractal.pi;
		if ((fractal.newre * fractal.newre + fractal.newim * fractal.newim) > 4)
			break ;
		i++;
	}
	return (i);
}

void	draw(t_mlx *mlx, int f)
{
	int x;
	int y;
	int color;
	int fn;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (f == 1)
				fn = mandelbrot(mlx->fractal, x, y);
			else if (f == 2)
				fn = julia(mlx->fractal, x, y);
			else if (f == 3)
				fn = tricorn(mlx->fractal, x, y);
			color = ((fn == mlx->fractal.max) ? 0x000000 : fn * mlx->color);
			pixelate(mlx, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->str.img, 0, 0);
}

int		get_fractal_type(int f)
{
	int fr;

	fr = 0;
	if (f == 1)
		fr = 1;
	else if (f == 2)
		fr = 2;
	else if (f == 3)
		fr = 3;
	else
		ft_puterror("Usage: ./fractal [1 = Man 2 = Julia 3 = Tri]", 1);
	return (fr);
}
