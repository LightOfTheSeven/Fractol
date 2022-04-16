#include "../include/fractol.h"

void	init_main(int argc, char **argv, struct mlx_s *mlx, struct maths_s *maths)
{
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
	    mandelbrot_draw(maths, mlx, mlx);
	    mlx->fract = 1;
	}
	else if (!ft_strcmp(argv[1], "julia"))
	{
	     if (argc >= 4)
	     {
		    maths->pr = ft_atoi_float(argv[2]);
		    maths->pi = ft_atoi_float(argv[3]);
		    maths->arg = 1;
	     }
	     else
		     maths->arg = 0;
	     julia_draw(maths, mlx, mlx);
	     mlx->fract = 2;
	}
	else if (!ft_strcmp(argv[1], "burningship"))
	{
	    burningship_draw(maths, mlx, mlx);
	    mlx->fract = 3;
	}
}

int main(int argc, char **argv)
{
    struct mlx_s	mlx;
    struct maths_s	maths;

    if (argc < 2 || (ft_strcmp(argv[1], "julia") && ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "burningship")))
	    exit_frac(EXIT_FAILURE);
    start_mlx(&mlx);
    maths_init(&maths);
    mlx.maths = &maths;
    init_main(argc, argv, &mlx, &maths);
    mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
    hook(&mlx);
    return (0);
}
