#include "../include/fractol.h"

void	color_change(struct mlx_s *mlx, int key)
{
	if (key == minus)
		mlx->choice = mlx->choice - 1;
	if (key == plus)
		mlx->choice = mlx->choice + 1;
	return;
}

void	move(struct maths_s *maths, struct mlx_s *mlx, double x, double y)
{
		maths->movex = maths->movex + (x - (mlx->sizex / 2)) / 800 / (maths->zoom * 4);
		maths->movey = maths->movey + (y - (mlx->sizey / 2)) / 800 / (maths->zoom * 4);
	return;
}

void	move_with_arrows(struct mlx_s *mlx, int key)
{
	int i;

	i = 100;
	if (key == right)
		move(mlx->maths, mlx, mlx->sizex * 3/4, mlx->sizey/2);
	if (key == left)
		move(mlx->maths, mlx, mlx->sizex * 1/4, mlx->sizey/2);
	if (key == low)
		move(mlx->maths, mlx, mlx->sizex/2, mlx->sizey * 3/4);
	if (key == high)
		move(mlx->maths, mlx, mlx->sizex/2, mlx->sizey * 1/4);
	return;
}

void	zoom(struct maths_s *maths, double i)
{
	maths->zoom = maths->zoom * i;
	return;
}
