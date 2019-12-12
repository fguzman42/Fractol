/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:06:05 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/03 14:56:10 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	pixelate(t_mlx *mlx, int x, int y, int color)
{
	unsigned int ucol;

	ucol = mlx_get_color_value(mlx->init, color);
	ft_memcpy(mlx->str.data + 4 * WIN_WIDTH * y + x * 4, &ucol, sizeof(int));
}

void	zoomio(t_mlx *mlx, int keys)
{
	if (keys == 69)
	{
		mlx->fractal.zoom += 0.3 * mlx->fractal.zoom;
		draw(mlx, mlx->f);
	}
	if (keys == 78)
	{
		mlx->fractal.zoom -= 0.3 * mlx->fractal.zoom;
		draw(mlx, mlx->f);
	}
}

void	udlr(t_mlx *mlx, int key)
{
	if (key == 126)
	{
		mlx->fractal.movey -= 0.1 / mlx->fractal.zoom;
		draw(mlx, mlx->f);
	}
	if (key == 125)
	{
		mlx->fractal.movey += 0.1 / mlx->fractal.zoom;
		draw(mlx, mlx->f);
	}
	if (key == 124)
	{
		mlx->fractal.movex -= 0.1 / mlx->fractal.zoom;
		draw(mlx, mlx->f);
	}
	if (key == 123)
	{
		mlx->fractal.movex += 0.1 / mlx->fractal.zoom;
		draw(mlx, mlx->f);
	}
}

void	set_init(t_mlx *mlx, int f)
{
	mlx->color = 461058;
	mlx->str.bpp = 0;
	mlx->str.size_line = 0;
	mlx->str.endian = 0;
	mlx->str.data = mlx_get_data_addr(mlx->str.img, &mlx->str.bpp,
			&mlx->str.size_line, &mlx->str.endian);
	if (f == 1)
		set_fractalm(&mlx->fractal);
	if (f == 2)
		set_fractalj(&mlx->fractal);
	if (f == 3)
		set_fractalb(&mlx->fractal);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc == 2)
	{
		mlx.f = get_fractal_type(ft_atoi(argv[1]));
		mlx.init = mlx_init();
		mlx.win = mlx_new_window(mlx.init, WIN_WIDTH,
				WIN_HEIGHT, "franco's fractal");
		mlx.str.img = mlx_new_image(mlx.init, WIN_WIDTH, WIN_HEIGHT);
		set_init(&mlx, mlx.f);
		draw(&mlx, mlx.f);
		mlx_key_hook(mlx.win, keys, (void *)&mlx);
		mlx_mouse_hook(mlx.win, keys2, (void *)&mlx);
		mlx_hook(mlx.win, 6, 0, juliamouse, &mlx);
		mlx_loop(mlx.init);
	}
	else
		ft_puterror("Usage: ./fractal [1 = Man 2 = Julia 3 = Tri]", 1);
	return (0);
}
