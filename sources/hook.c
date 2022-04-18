/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:30:39 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 18:51:47 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	deal_key(int key, void *param)
{
	if (key == ESC)
		exit_mlx(param);
	if (key == PLUS || key == MINUS)
	{
		color_change(param, key);
		draw_image(param);
	}
	if (key == RIGHT || key == LEFT || key == HIGH || key == LOW)
	{
		move_with_arrows(param, key);
		draw_image(param);
	}
	return (0);
}

int	deal_mouse(int mousecode, int x, int y, t_mlx *mlx)
{
	if (mousecode == 4)
		zoom(mlx->maths, 1.4);
	if (mousecode == 5)
		zoom(mlx->maths, 0.6);
	if (mousecode == 1 || mousecode == 4 || mousecode == 5)
		move(mlx->maths, mlx, x, y);
	draw_image(mlx);
	return (0);
}

void	hook(struct s_mlx *mlx)
{
	mlx_hook(mlx->win, 33, 1L << 17, exit_mlx, mlx);
	mlx_key_hook(mlx->win, deal_key, mlx);
	mlx_mouse_hook(mlx->win, deal_mouse, mlx);
	mlx_loop(mlx->ptr);
}
