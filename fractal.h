/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:22:48 by fguzman           #+#    #+#             */
/*   Updated: 2019/12/03 14:26:40 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# define WIN_WIDTH 900
# define WIN_HEIGHT 600

typedef struct	s_fractal
{
	double	pr;
	double	pi;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	zoom;
	double	movex;
	double	movey;
	int		i;
	int		y;
	int		x;
	int		max;
}				t_fractal;

typedef struct	s_data
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
}				t_data;

typedef struct	s_mlx
{
	int			color;
	int			f;
	void		*init;
	void		*win;
	t_data		str;
	t_fractal	fractal;
}				t_mlx;

void			pixelate(t_mlx *mlx, int x, int y, int color);
void			draw(t_mlx *mlx, int f);
void			set_fractalm(t_fractal *fractal);
void			set_init(t_mlx *mlx, int f);
void			set_fractalj(t_fractal *fractal);
void			set_fractalb(t_fractal *fractal);
int				keys(int key, t_mlx *mlx);
int				keys2(int key, int x, int y, t_mlx *mlx);
void			mouseio(t_mlx *mlx, int key);
void			mliteration(t_mlx *mlx, int key);
void			reset(t_mlx *mlx, int f);
unsigned int	a_value(int point);
void			set_fractalb(t_fractal *fractal);
void			set_fractalm(t_fractal *fractal);
void			mouseio(t_mlx *mlx, int key);
void			udlr(t_mlx *mlx, int key);
void			zoomio(t_mlx *mlx, int keys);
int				juliamouse(int x, int y, t_mlx *mlx);
int				get_fractal_type(int f);
#endif
