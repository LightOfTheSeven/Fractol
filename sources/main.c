/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:36:30 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 18:40:26 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_main(int argc, char **argv, t_mlx *mlx, t_maths *maths)
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
			maths->pr = ft_atod(argv[2]);
			maths->pi = ft_atod(argv[3]);
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

int	main(int argc, char **argv)
{
	struct s_mlx	mlx;
	struct s_maths	maths;

	if (argc < 2 || (ft_strcmp(argv[1], "julia") && ft_strcmp
			(argv[1], "mandelbrot") && ft_strcmp(argv[1], "burningship")))
		exit_frac(EXIT_FAILURE);
	if (start_mlx(&mlx) == 1)
	{
		ft_putstr("Erreur : Il n'y a pas d'environnement\n");
		return (1);
	}
	maths_init(&maths);
	mlx.maths = &maths;
	init_main(argc, argv, &mlx, &maths);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	hook(&mlx);
	return (0);
}
