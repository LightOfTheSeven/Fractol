#include "../include/fractol.h"

void	exit_frac(int status)
{
	printf("erreur : parametre invalide\n");
	printf("1er arg: 'julia', 'mandelbrot' ou 'burningship'\n");
	printf("2e et 3e arg : partie réelle et imaginaire de c pour la fractale de Julia\n");
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
