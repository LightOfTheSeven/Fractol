/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:44:28 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 18:57:21 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot_julia_maths(t_maths *maths)
{
	int	i;

	i = 0;
	while (i < maths->max_iteration)
	{
		maths->oldre = maths->newre;
		maths->oldim = maths->newim;
		maths->newre = (maths->oldre * maths->oldre)
			- (maths->oldim * maths->oldim) + maths->pr;
		maths->newim = 2 * maths->oldre * maths->oldim + maths->pi;
		if (maths->newre * maths->newre + maths->newim * maths->newim > 4)
			break ;
		i++;
	}
	return (i);
}

int	burningship_maths(t_maths *maths)
{
	int	i;

	i = 0;
	while (i < maths->max_iteration)
	{
		if (maths->newre >= 0)
			maths->oldre = maths->newre;
		else
			maths->oldre = -maths->newre;
		if (maths->newim >= 0)
			maths->oldim = maths->newim;
		else
			maths->oldim = -maths->newim;
		maths->newre = (maths->oldre * maths->oldre)
			- (maths->oldim * maths->oldim) + maths->pr;
		maths->newim = 2 * maths->oldre * maths->oldim + maths->pi;
		if (maths->newre * maths->newre + maths->newim * maths->newim > 4)
			break ;
		i++;
	}
	return (i);
}
