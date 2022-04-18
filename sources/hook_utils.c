/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:31:41 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 18:55:26 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_change(t_mlx *mlx, int key)
{
	if (key == MINUS)
		mlx->choice = mlx->choice - 1;
	if (key == PLUS)
		mlx->choice = mlx->choice + 1;
	return ;
}

void	move(t_maths *maths, t_mlx *mlx, double x, double y)
{
		maths->movex = maths->movex + (x
			- (mlx->sizex / 2)) / 800 / (maths->zoom * 4);
		maths->movey = maths->movey + (y
			- (mlx->sizey / 2)) / 800 / (maths->zoom * 4);
	return ;
}

void	move_with_arrows(t_mlx *mlx, int key)
{
	int	i;

	i = 100;
	if (key == RIGHT)
		move(mlx->maths, mlx, mlx->sizex * 3 / 4, mlx->sizey / 2);
	if (key == LEFT)
		move(mlx->maths, mlx, mlx->sizex * 1 / 4, mlx->sizey / 2);
	if (key == LOW)
		move(mlx->maths, mlx, mlx->sizex / 2, mlx->sizey * 3 / 4);
	if (key == HIGH)
		move(mlx->maths, mlx, mlx->sizex / 2, mlx->sizey * 1 / 4);
	return ;
}

void	zoom(t_maths *maths, double i)
{
	maths->zoom = maths->zoom * i;
	return ;
}
