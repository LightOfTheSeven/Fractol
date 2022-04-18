/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:35:53 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 18:56:06 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	start_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return (1);
	mlx_get_screen_size(mlx->ptr, &mlx->sizex, &mlx->sizey);
	mlx->sizex = 1200;
	mlx->sizey = 1200;
	mlx->choice = 1;
	mlx->win = mlx_new_window(mlx->ptr, mlx->sizex, mlx->sizey, "fractol");
	mlx->img = mlx_new_image(mlx->ptr, mlx->sizex, mlx->sizey);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->len, &mlx->endian);
	return (0);
}

void	maths_init(t_maths *maths)
{
	maths->max_iteration = 128;
	maths->movex = -0.5;
	maths->movey = 0.25;
	maths->zoom = 0.25;
	return ;
}
