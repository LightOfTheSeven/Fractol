#include "../include/fractol.h"

void	pixel_draw(struct mlx_s *mlx, int x, int y, int color)
{
	char *dst;
	dst = mlx->addr + (y * mlx->len + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_image(struct mlx_s *mlx)
{
	struct mlx_s temp;
	
	mlx_destroy_image(mlx->ptr, mlx->img);
	temp.img = mlx_new_image(mlx->ptr, mlx->sizex, mlx->sizey);
	temp.addr = mlx_get_data_addr(temp.img, &temp.bpp, &temp.len, &temp.endian);
	if(mlx->fract == 1)
		mandelbrot_draw(mlx->maths, &temp, mlx);
	else if (mlx->fract == 2)
		julia_draw(mlx->maths, &temp, mlx);
	else if (mlx->fract == 3)
		burningship_draw(mlx->maths, &temp, mlx);
	mlx->img = temp.img;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return;
}

void	mandelbrot_draw(struct maths_s *maths, struct mlx_s *tempMlx, struct mlx_s *mlx)
{
	int x;
	int y;
	int nb_iteration;

	x = 0;
	while (x < mlx->sizex)
	{
		y = 0;
		while (y < mlx->sizey)
		{
			maths->pr = (x - mlx->sizex / 2) / (maths->zoom * mlx->sizex) + maths->movex;
			maths->pi = (y - mlx->sizey / 2) / (maths->zoom * mlx->sizey) + maths->movey;
			maths->oldRe = 0;
			maths->oldIm = 0;
			maths->newRe = 0;
			maths->newIm = 0;
			nb_iteration = mandelbrotJulia_maths(maths);
			maths->color = choice_rgb(mlx, nb_iteration);
			pixel_draw(tempMlx, x, y, maths->color);
			y++;
		}
		x++;
	}
	return;
}

void	julia_draw(struct maths_s *maths, struct mlx_s *tempMlx, struct mlx_s *mlx)
{
	int x;
	int y;
	int nb_iteration;

	x = 0;
	if (maths->arg == 0)
	{
		maths->pr = -0.4;
		maths->pi = 0.6;
	}
	while (x < mlx->sizex)
	{
		y = 0;
		while (y < mlx->sizey)
		{
			maths->newRe = (x - mlx->sizex / 2) / (maths->zoom * mlx->sizex) + maths->movex;
			maths->newIm = (y - mlx->sizey / 2) / (maths->zoom * mlx->sizey) + maths->movey;
			nb_iteration = mandelbrotJulia_maths(maths);
			maths->color = choice_rgb(mlx, nb_iteration);
			pixel_draw(tempMlx, x, y, maths->color);
			y++;
		}
		x++;
	}
	return;
}

void	burningship_draw(struct maths_s *maths, struct mlx_s *tempMlx, struct mlx_s *mlx)
{
	int x;
	int y;
	int nb_iteration;

	x = 0;
	while (x < mlx->sizex)
	{
		y = 0;
		while (y < mlx->sizey)
		{
			maths->pr = (x - mlx->sizex / 2) / (maths->zoom * mlx->sizex) + maths->movex;
			maths->pi = (y - mlx->sizey / 2) / (maths->zoom * mlx->sizey) + maths->movey;
			maths->oldRe = 0;
			maths->oldIm = 0;
			maths->newRe = 0;
			maths->newIm = 0;
			nb_iteration = burningship_maths(maths);
			maths->color = choice_rgb(mlx, nb_iteration);
			pixel_draw(tempMlx, x, y, maths->color);
			y++;
		}
		x++;
	}
	return;
}
