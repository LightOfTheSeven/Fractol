#include "../include/fractol.h"

int	choice123(int i, struct rgb_s *rgb, int choice)
{
	rgb->r = i*2*choice;
	rgb->g = i*2*choice;
	rgb->b = i*2*choice;
	return(0);
}

int	choice456(int i, struct rgb_s *rgb, int choice)
{
	rgb->r = i *2 * (choice-2);
	rgb->g = 0;
	rgb->b = i *2;
	return(0);
}

int	choice789(int i, struct rgb_s *rgb, int choice)
{	if (choice == 7)
	{
		rgb->r = i * (255-i) * 2;
		rgb->g = i * (150-i) * 3;
		rgb->b = i * (190-i) * 4;
	}
	else if (choice == 8)
	{
		rgb->r = i * (255-i) * 4;
		rgb->g = i * (150-i) * 9;
		rgb->b = i * (190-i);
	}
	else
	{
		rgb->r = i * (128-i);
		rgb->g = i * (230-i);
		rgb->b = i * (800-i);
	}
	return(0);
}

int	choice10plus(int i, struct rgb_s *rgb, int choice)
{	if (choice == 10)
	{
		rgb->r = i * 2i;
		rgb->g = i * 3i;
		rgb->b = i * i;

	}
	else if (choice == 11)
	{
		rgb->r = i * i;
		rgb->g = i * 2i;
		rgb->b = i * 3i;
	}
	else
	{
		rgb->r = i * 3i;
		rgb->g = i * i;
		rgb->b = i * 2i;
	}
	return(0);
}

int	choice_rgb(struct mlx_s *mlx, int iteration)
{
	struct rgb_s rgb;

	if (mlx->choice == 1 | mlx->choice == 13)
	{
		mlx->choice = 1;
		choice123(iteration, &rgb, mlx->choice);
	}
	else if (mlx->choice == 2 | mlx->choice == 3)
		choice123(iteration, &rgb, mlx->choice);
	else if (mlx->choice == 4 | mlx->choice == 5 | mlx->choice == 6)
		choice456(iteration, &rgb, mlx->choice);
	else if (mlx->choice == 7 | mlx->choice == 8 | mlx->choice == 9)
		choice789(iteration, &rgb, mlx->choice);
	else if (mlx->choice == 10 | mlx-> choice == 11)
		choice10plus(iteration, &rgb, mlx->choice);
	else
	{
		mlx->choice = 12;
		choice10plus(iteration, &rgb, mlx->choice);
	}
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}


