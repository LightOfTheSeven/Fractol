/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:57:28 by abourrel          #+#    #+#             */
/*   Updated: 2022/04/18 14:09:51 by abourrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_putchar2(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr2(int n)
{
	if (n < 0)
	{
		ft_putchar2('-');
		ft_putchar2(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr2(n / 10);
		ft_putchar2(n % 10 + '0');
		return ;
	}
	else
	{
		ft_putchar2(n % 10 + '0');
		return ;
	}
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] || b[i])
	{
		if (a[i] == b[i])
			i++;
		else
			return(a[i] - b[i]);
	}
	return (a[i] - b[i]);
}

double	ft_atod2(char *str, int i, double nb, double signe)
{
	int j;
	
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (double)str[i] - 48.0 + nb * 10.0;
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
	{
		j = 10.0;
		i++;
	}
	else
		return (nb * signe);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = ((double)str[i] - 48.0) * 1.0 / j + nb;
		j = j * 10.0;
		i++;
	}

	return (nb * signe);
}

double	ft_atod(char *str)
{
	double	signe;
	double	nb;
	int	i;

	signe = 1.0;

	nb = 0.0;
	i = 0;

	if (!str)
		return (1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1.0;
		i++;
	}
	return (ft_atod2(str, i, nb, signe));
}
