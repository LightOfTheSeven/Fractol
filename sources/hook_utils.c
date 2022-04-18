/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:31:41 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 13:35:29 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_change(mlx_t *mlx, int key)
{
	if (key == minus)
		mlx->choice = mlx->choice - 1;
	if (key == plus)
		mlx->choice = mlx->choice + 1;
	return ;
}

void	move(maths_t *maths, mlx_t *mlx, double x, double y)
{
		maths->movex = maths->movex + (x
			- (mlx->sizex / 2)) / 800 / (maths->zoom * 4);
		maths->movey = maths->movey + (y
			- (mlx->sizey / 2)) / 800 / (maths->zoom * 4);
	return ;
}

void	move_with_arrows(mlx_t *mlx, int key)
{
	int	i;

	i = 100;
	if (key == right)
		move(mlx->maths, mlx, mlx->sizex * 3 / 4, mlx->sizey / 2);
	if (key == left)
		move(mlx->maths, mlx, mlx->sizex * 1 / 4, mlx->sizey / 2);
	if (key == low)
		move(mlx->maths, mlx, mlx->sizex / 2, mlx->sizey * 3 / 4);
	if (key == high)
		move(mlx->maths, mlx, mlx->sizex / 2, mlx->sizey * 1 / 4);
	return ;
}

void	zoom(maths_t *maths, double i)
{
	maths->zoom = maths->zoom * i;
	return ;
}
