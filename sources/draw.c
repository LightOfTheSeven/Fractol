/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:09:55 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 18:48:37 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	pixel_draw(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_image(t_mlx *mlx)
{
	struct s_mlx	temp;

	mlx_destroy_image(mlx->ptr, mlx->img);
	temp.img = mlx_new_image(mlx->ptr, mlx->sizex, mlx->sizey);
	temp.addr = mlx_get_data_addr(temp.img, &temp.bpp, &temp.len, &temp.endian);
	if (mlx->fract == 1)
		mandelbrot_draw(mlx->maths, &temp, mlx);
	else if (mlx->fract == 2)
		julia_draw(mlx->maths, &temp, mlx);
	else if (mlx->fract == 3)
		burningship_draw(mlx->maths, &temp, mlx);
	mlx->img = temp.img;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return ;
}

void	mandelbrot_draw(t_maths *maths, t_mlx *tempMlx, t_mlx *mlx)
{
	int	x;
	int	y;
	int	nb_iteration;

	x = 0;
	while (x < mlx->sizex)
	{
		y = 0;
		while (y < mlx->sizey)
		{
			maths->pr = (x - mlx->sizex / 2) / (maths->zoom
					* mlx->sizex) + maths->movex;
			maths->pi = (y - mlx->sizey / 2) / (maths->zoom
					* mlx->sizey) + maths->movey;
			maths->oldre = 0;
			maths->oldim = 0;
			maths->newre = 0;
			maths->newim = 0;
			nb_iteration = mandelbrot_julia_maths(maths);
			maths->color = choice_rgb(mlx, nb_iteration);
			pixel_draw(tempMlx, x, y, maths->color);
			y++;
		}
		x++;
	}
}

void	julia_draw(t_maths *maths, t_mlx *tempMlx, t_mlx *mlx)
{
	int	x;
	int	y;
	int	nb_iteration;

	x = -1;
	if (maths->arg == 0)
	{
		maths->pr = -0.4;
		maths->pi = 0.6;
	}
	while (++x < mlx->sizex)
	{
		y = -1;
		while (++y < mlx->sizey)
		{
			maths->newre = (x - mlx->sizex / 2) / (maths->zoom
					* mlx->sizex) + maths->movex;
			maths->newim = (y - mlx->sizey / 2) / (maths->zoom
					* mlx->sizey) + maths->movey;
			nb_iteration = mandelbrot_julia_maths(maths);
			maths->color = choice_rgb(mlx, nb_iteration);
			pixel_draw(tempMlx, x, y, maths->color);
		}
	}
}

void	burningship_draw(t_maths *maths, t_mlx *tempMlx, t_mlx *mlx)
{
	int	x;
	int	y;
	int	nb_iteration;

	x = -1;
	while (++x < mlx->sizex)
	{
		y = -1;
		while (++y < mlx->sizey)
		{
			maths->pr = (x - mlx->sizex / 2) / (maths->zoom
					* mlx->sizex) + maths->movex;
			maths->pi = (y - mlx->sizey / 2) / (maths->zoom
					* mlx->sizey) + maths->movey;
			maths->oldre = 0;
			maths->oldim = 0;
			maths->newre = 0;
			maths->newim = 0;
			nb_iteration = burningship_maths(maths);
			maths->color = choice_rgb(mlx, nb_iteration);
			pixel_draw(tempMlx, x, y, maths->color);
		}
	}
	return ;
}
