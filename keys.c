/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 03:20:49 by fguzman           #+#    #+#             */
/*   Updated: 2019/11/28 02:36:17 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	reset(t_mlx *mlx, int f)
{
	set_init(mlx, f);
	draw(mlx, mlx->f);
}

void	mliteration(t_mlx *mlx, int key)
{
	if (key == 34)
	{
		mlx->fractal.max += 1;
		draw(mlx, mlx->f);
	}
	if (key == 31)
	{
		mlx->fractal.max -= 1;
		draw(mlx, mlx->f);
	}
}

void	mouseio(t_mlx *mlx, int key)
{
	if (key == 4)
	{
		mlx->fractal.zoom *= 1.09;
		draw(mlx, mlx->f);
	}
	if (key == 5)
	{
		mlx->fractal.zoom /= 1.09;
		draw(mlx, mlx->f);
	}
}

int		keys2(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == 4 || key == 5)
		mouseio(mlx, key);
	return (0);
}

int		keys(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	if (key == 69 || key == 78)
		zoomio(mlx, key);
	if (key >= 123 && key <= 126)
		udlr(mlx, key);
	if (key == 15)
		reset(mlx, mlx->f);
	if (key == 34 || key == 31)
		mliteration(mlx, key);
	if (key == 8)
	{
		mlx->color += 5121;
		draw(mlx, mlx->f);
	}
	return (0);
}
