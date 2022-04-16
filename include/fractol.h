
#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../libmlx/mlx.h"

# define ESC 65307
# define plus 65451
# define minus 65453
# define high 65362
# define low 65364
# define left 65361
# define right 65363

typedef struct    mlx_s
{
	void	*ptr;
	void	*win;
	int	sizex;
	int	sizey;
	struct s_img	*img;
	char	*addr;
	int	bpp;
	int	len;
	int	endian;
	void	*maths;
	int	choice;
	int	fract;

}           mlx_t;

typedef struct	maths_s
{
	double pr;
	double pi;
	int color;
	double newRe;
	double newIm;
	double oldRe;
	double oldIm;
	int max_iteration;
	double movex;
	double movey;
	double zoom;
	int arg;
}	maths_t;

typedef struct	rgb_s
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	rgb_t;

int	choice_rgb(struct mlx_s *mlx, int iteration);
void	draw_image(struct mlx_s *mlx);
void	mandelbrot_draw(struct maths_s *maths, struct mlx_s *tempMlx, struct mlx_s *mlx);
void	julia_draw(struct maths_s *maths, struct mlx_s *tempMlx, struct mlx_s *mlx);
void	burningship_draw(struct maths_s *maths, struct mlx_s *tempMlx, struct mlx_s *mlx);
void	exit_frac(int status);
int	exit_mlx(struct mlx_s *mlx);
void	hook(struct mlx_s *mlx);
void	color_change(struct mlx_s *mlx, int key);
void	move(struct maths_s *maths, struct mlx_s *mlx, double x, double y);
void	move_with_arrows(struct mlx_s *mlx, int key);
void	zoom(struct maths_s *maths, double i);
void	start_mlx(struct mlx_s *mlx);
void	maths_init(struct maths_s *maths);
int	mandelbrotJulia_maths(struct maths_s *maths);
int	burningship_maths(struct maths_s *maths);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int	ft_strcmp(char *a, char *b);
double	ft_atoi_float(char *str);

#endif
