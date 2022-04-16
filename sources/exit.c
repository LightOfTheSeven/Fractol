#include "../include/fractol.h"

void	exit_frac(int status)
{
	printf("error: invalid parameter\n");
	printf("1st arg: 'julia', 'mandelbrot' or 'burningship'\n");
	exit(status);
}

int	exit_mlx(struct mlx_s *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	mlx->ptr = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}
