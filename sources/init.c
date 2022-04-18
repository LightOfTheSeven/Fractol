/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:35:53 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 13:36:14 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	start_mlx(struct mlx_s *mlx)
{
	mlx->ptr = mlx_init();
	mlx_get_screen_size(mlx->ptr, &mlx->sizex, &mlx->sizey);
	mlx->sizex = 1200;
	mlx->sizey = 1200;
	mlx->choice = 1;
	mlx->win = mlx_new_window(mlx->ptr, mlx->sizex, mlx->sizey, "fractol");
	mlx->img = mlx_new_image(mlx->ptr, mlx->sizex, mlx->sizey);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->len, &mlx->endian);
	return ;
}

void	maths_init(struct maths_s *maths)
{
	maths->max_iteration = 128;
	maths->movex = -0.5;
	maths->movey = 0.25;
	maths->zoom = 0.25;
	return ;
}
