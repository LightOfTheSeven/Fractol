/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:14:07 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 19:12:20 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../libmlx/mlx.h"

# define ESC 65307
# define PLUS 65451
# define MINUS 65453
# define HIGH 65362
# define LOW 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	int				sizex;
	int				sizey;
	struct s_img	*img;
	char			*addr;
	int				bpp;
	int				len;
	int				endian;
	void			*maths;
	int				choice;
	int				fract;

}	t_mlx;

typedef struct s_maths
{
	double		pr;
	double		pi;
	int			color;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	int			max_iteration;
	double		movex;
	double		movey;
	double		zoom;
	int			arg;
}	t_maths;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

int		choice_rgb(t_mlx *mlx, int iteration);
void	draw_image(t_mlx *mlx);
void	mandelbrot_draw(t_maths *maths, t_mlx *tempMlx, t_mlx *mlx);
void	julia_draw(t_maths *maths, t_mlx *tempMlx, t_mlx *mlx);
void	burningship_draw(t_maths *maths, t_mlx *tempMlx, t_mlx *mlx);
void	exit_frac(int status);
int		exit_mlx(t_mlx *mlx);
void	hook(t_mlx *mlx);
void	color_change(t_mlx *mlx, int key);
void	move(t_maths *maths, t_mlx *mlx, double x, double y);
void	move_with_arrows(t_mlx *mlx, int key);
void	zoom(t_maths *maths, double i);
int		start_mlx(t_mlx *mlx);
void	maths_init(t_maths *maths);
int		mandelbrot_julia_maths(t_maths *maths);
int		burningship_maths(t_maths *maths);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *c);
int		ft_strcmp(char *a, char *b);
double	ft_atod(char *str);

#endif
