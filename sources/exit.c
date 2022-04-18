/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:28:58 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 18:49:44 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while(c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
}

void	exit_frac(int status)
{
	ft_putstr("erreur : parametre invalide\n");
	ft_putstr("1er arg: 'julia', 'mandelbrot' ou 'burningship'\n");
	ft_putstr("2e et 3e arg : partie réelle et imaginaire de c");
	ft_putstr(" pour la fractale de Julia\n");
	exit(status);
}

int	exit_mlx(t_mlx *mlx)
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
